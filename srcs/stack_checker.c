/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                stack_sorted                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:22:14 by florian           #+#    #+#             */
/*   Updated: 2024/02/06 16:22:14 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if(stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int stack_lenght(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}