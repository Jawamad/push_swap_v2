/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:27:37 by florian           #+#    #+#             */
/*   Updated: 2024/04/09 18:36:28 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*previousnode;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	node->next = NULL;
	if (!*stack)
		*stack = node;
	else
	{
		previousnode = lnode_finder(*stack);
		previousnode->next = node;
	}
}

void	set_target(t_stack *node, t_stack *st_target)
{
	int		diff;
	t_stack	*temp_st_target;

	temp_st_target = st_target;
	diff = 0;
	while (temp_st_target)
	{
		if ((node)->value > temp_st_target->value)
		{
			if (!diff || (diff > (node->value - temp_st_target->value)))
			{
				diff = node->value - temp_st_target->value ;
				node->target_node = temp_st_target;
			}
		}
		temp_st_target = temp_st_target->next;
	}
	if (!diff)
		node->target_node = find_biggest(st_target);
}

void	set_reverse_target(t_stack *node, t_stack *st_target)
{
	int		diff;
	t_stack	*temp_st_target;

	temp_st_target = st_target;
	diff = 0;
	while (temp_st_target)
	{
		if ((node)->value < temp_st_target->value)
		{
			if (!diff || (diff < (node->value - temp_st_target->value)))
			{
				diff = node->value - temp_st_target->value;
				node->target_node = temp_st_target;
			}
		}
		temp_st_target = temp_st_target->next;
	}
	if (!diff)
		node->target_node = find_lowest(st_target);
}

void	reset_attribute(t_stack *stack)
{
	int	i;
	int	median;

	median = stack_lenght(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		stack->cheapest = 0;
		stack->above_median = 0;
		if (i > median)
			stack->above_median = 1;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	cheapest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->push_cost < cheapest_node->push_cost)
			cheapest_node = stack;
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
