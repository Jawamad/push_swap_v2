/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:07 by florian           #+#    #+#             */
/*   Updated: 2024/02/15 15:31:07 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *tempnode;

	tempnode = *stack;
	*stack = (*stack)->next;
	tempnode->next = (*stack)->next;
	(*stack)->next = tempnode;	
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tempnode;

	tempnode = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_1)->next = tempnode;
	(*stack_2)->next = *stack_1;
}

void	rotate(t_stack **stack)
{
	t_stack	*tempnode;

	tempnode = *stack;
	tempnode->next = NULL;
	lnode_finder(*stack)->next = tempnode;
	*stack = (*stack)->next;
}

void	rrotate(t_stack **stack)
{
	t_stack	*tempnode;
	t_stack	*lastnode;

	lastnode = lnode_finder(*stack);
	tempnode = *stack;
	while ((*stack)->next != lastnode)
		*stack = (*stack)->next;
	*stack = NULL;
	lastnode->next = tempnode;
}