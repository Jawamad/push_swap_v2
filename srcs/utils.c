/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:42:41 by florian           #+#    #+#             */
/*   Updated: 2024/02/13 17:33:57 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(const char *nptr)
{
	int	i;
	int	sign;
	long	res;

	sign = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

int	free_stack(t_stack **stack, char **arv, int code_err)
{
	t_stack	*temp_node;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
	if (code_err == 1)
	{
		free_arv(arv);
		return (write(1, "Error", 5), exit(1), 0);
	}
	return (0);
}

void	free_arv(char **arv)
{
	int	i;

	i = 0;
	while (arv[i])
		free(arv[i++]);
}

