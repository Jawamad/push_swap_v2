/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:58:40 by florian           #+#    #+#             */
/*   Updated: 2024/04/09 18:55:30 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (stack_lenght(*a) > 3)
	{
		push_move(b, a, 2);
		push_move(b, a, 2);
		while (stack_lenght(*a) > 3)
		{
			reset_a(a, b);
			rotate_to_move(a, b);
		}
		if (!stack_sorted(*a))
			sort_3(a);
		while (*b)
		{
			reset_b(a, b);
			push_b_to_a(a, b);
		}
		min_rotate(a);
	}
	else
	{
		sort_3(a);
	}
}

void	sort_3(t_stack **a)
{
	t_stack	*max;

	max = find_biggest(*a);
	if (*a == max)
		simple_move(a, rotate, 3);
	else if ((*a)->next == max)
		simple_move(a, rrotate, 5);
	if ((*a)->value > (*a)->next->value)
		simple_move(a, swap, 1);
}

void	min_rotate(t_stack **a)
{
	t_stack	*min;

	min = find_lowest(*a);
	while (min != (*a))
	{
		if (min->above_median)
			simple_move(a, rrotate, 5);
		else
			simple_move(a, rotate, 3);
	}
}

int	stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
