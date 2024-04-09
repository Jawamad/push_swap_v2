/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:07 by florian           #+#    #+#             */
/*   Updated: 2024/04/08 21:20:19 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tempnode;

	tempnode = *stack;
	*stack = (*stack)->next;
	tempnode->next = (*stack)->next;
	(*stack)->next = tempnode;
}

/* push de la stack 2 vers la 1 */
void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tempnode;

	tempnode = *stack_2;
	*stack_2 = (*stack_2)->next;
	tempnode->next = NULL;
	ft_stackadd_front(stack_1, tempnode);
}

void	rotate(t_stack **stack)
{
	t_stack	*tempnode;

	tempnode = *stack;
	*stack = (*stack)->next;
	lnode_finder(*stack)->next = tempnode;
	tempnode->next = NULL;
}

void	rrotate(t_stack **stack)
{
	t_stack	*tempnode;

	tempnode = *stack;
	while (tempnode->next->next)
		tempnode = tempnode->next;
	tempnode->next->next = *stack;
	*stack = tempnode->next;
	tempnode->next = NULL;
}
