/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:28:38 by florian           #+#    #+#             */
/*   Updated: 2024/04/08 21:23:14 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_to_move(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (!cheapest->above_median && !cheapest->target_node->above_median)
		double_rotate(a, b, cheapest, 0);
	else if (cheapest->above_median && cheapest->target_node->above_median)
		double_rotate(a, b, cheapest, 1);
	latests_rotate(a, cheapest, 3);
	latests_rotate(b, cheapest->target_node, 4);
	push_move(b, a, 2);
}

void	latests_rotate(t_stack **stack, t_stack *node, int move)
{
	if (node->above_median)
		while (*stack != node)
			simple_move(stack, rrotate, move + 2);
	else
		while (*stack != node)
			simple_move(stack, rotate, move);
}

void	double_rotate(t_stack **a, t_stack **b, t_stack	*cheapest, int dir)
{
	if (!dir)
	{
		while ((*a)->value != cheapest->value
			&& (*b)->value != cheapest->target_node->value)
			double_move(a, b, rotate, 2);
	}
	else
	{
		while ((*a)->value != cheapest->value
			&& (*b)->value != cheapest->target_node->value)
			double_move(a, b, rrotate, 3);
	}
	reset_attribute(*a);
	reset_attribute(*b);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	int	i;
	int	move;

	move = 0;
	i = (*b)->target_node->index;
	if ((*b)->target_node->above_median)
	{
		i = stack_lenght(*a) - i;
		move = 1;
	}
	while (i > 0)
	{
		if (move)
			simple_move(a, rrotate, 5);
		else
			simple_move(a, rotate, 3);
		i--;
	}
	push_move(a, b, 1);
}
