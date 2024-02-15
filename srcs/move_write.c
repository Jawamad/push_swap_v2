/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:04:55 by florian           #+#    #+#             */
/*   Updated: 2024/02/15 17:06:40 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	double_move(t_stack **a, t_stack **b ,void (*f)(t_stack **),int move)
{
	(*f)(a);
	(*f)(b);
	if (move == 1)
		write(1, "ss\n", 3);
	else if (move == 2)
		write(1, "rr\n", 3);
	else if (move == 3)
		write(1, "rrr\n", 4);
}

void	simple_move(t_stack **stack, void (*f)(t_stack **),int move)
{
	(*f)(stack);
	if (move == 1)
		write(1, "sa\n", 3);
	else if (move == 2)
		write(1, "sb\n", 3);
	else if (move == 3)
		write(1, "ra\n", 3);
	else if (move == 4)
		write(1, "rb\n", 3);
	else if (move == 5)
		write(1, "rra\n", 4);
	else if (move == 6)
		write(1, "rrb\n", 4);
}

void	push_move(t_stack **stack_1,t_stack **stack_2, int move)
{
	push(stack_1, stack_2);
	if (move == 1)
		write(1, "pa\n", 3);
	else if (move == 2)
		write(1, "pb\n", 3);
}