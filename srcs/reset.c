/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:44:10 by florian           #+#    #+#             */
/*   Updated: 2024/04/08 21:48:50 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reset_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	reset_attribute(*a);
	reset_attribute(*b);
	while (tmp)
	{
		set_target(tmp, *b);
		i++;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		calc_push_cost(tmp, *a, *b);
		tmp = tmp->next;
	}
	set_cheapest(*a);
}

void	reset_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	reset_attribute(*a);
	reset_attribute(*b);
	while (tmp)
	{
		set_reverse_target(tmp, *a);
		i++;
		tmp = tmp->next;
	}
}

void	calc_push_cost(t_stack *tmpa, t_stack *a, t_stack *b)
{
	if (!tmpa->target_node->above_median && !tmpa->above_median)
	{
		tmpa->push_cost = tmpa->index;
		if (tmpa->target_node->index > tmpa->index)
			tmpa->push_cost = tmpa->target_node->index;
	}
	else if (tmpa->target_node->above_median && tmpa->above_median)
	{
		tmpa->push_cost = stack_lenght(a) - tmpa->index;
		if (stack_lenght(b) - tmpa->target_node->index
			> stack_lenght(a) - tmpa->index)
			tmpa->push_cost = stack_lenght(b) - tmpa->target_node->index;
	}
	if (tmpa->target_node->above_median && !tmpa->above_median)
		tmpa->push_cost
			= (stack_lenght(b) - tmpa->target_node->index) + tmpa->index;
	if (!tmpa->target_node->above_median && tmpa->above_median)
		tmpa->push_cost = (stack_lenght(a) - tmpa->index)
			+ tmpa->target_node->index;
}
