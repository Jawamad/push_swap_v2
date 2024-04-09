/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:49:45 by florian           #+#    #+#             */
/*   Updated: 2024/04/09 19:10:05 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int arc, char **arv)
{
	t_stack	*a;
	t_stack	*b;
	int		err_code;

	a = NULL;
	b = NULL;
	err_code = 2;
	if ((arc == 1) || (arc == 2 && !arv[1][0]))
		return (0);
	else if (arc == 2)
	{
		arv = ft_split(arv[1], ' ');
		err_code = 1;
	}
	else
		arv = &arv[1];
	init_stack(&a, arv, err_code);
	if (!stack_sorted(a))
		sort(&a, &b);
	free_stack(&a, arv, 0);
	if (err_code == 1)
		free_arv(arv);
	return (0);
}
