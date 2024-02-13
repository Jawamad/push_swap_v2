/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:27:37 by florian           #+#    #+#             */
/*   Updated: 2024/02/13 17:10:23 by florian          ###   ########.fr       */
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

t_stack	*lnode_finder(t_stack *stack)
{
	while(stack->next)
		stack = stack->next;
	return (stack);
}