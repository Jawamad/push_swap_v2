/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:04:51 by florian           #+#    #+#             */
/*   Updated: 2024/04/08 21:50:44 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack **a, char **arv, int err_code)
{
	int		i;
	long	value;

	i = 0;
	while (arv[i])
	{
		if (check_syntax(arv[i]))
			free_stack(a, arv, err_code);
		value = ft_atol(arv[i]);
		if (value < -2147483648 || value > 2147483647)
			free_stack(a, arv, err_code);
		if (check_dupli(*a, (int)value))
			free_stack(a, arv, err_code);
		add_node(a, (int)value);
		i++;
	}
}

int	check_syntax(char *arv)
{
	int	symcheck;
	int	i;

	i = 0;
	symcheck = 0;
	while (arv[i])
	{
		if (ft_isdigit(arv[i]) || arv[i] == '-' || arv[i] == '+')
		{
			if (symcheck == 0)
				symcheck = 1;
			else
				if (arv[i] == '-' || arv[i] == '+')
					return (1);
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_dupli(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
