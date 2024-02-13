/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:49:45 by florian           #+#    #+#             */
/*   Updated: 2024/02/13 16:25:54 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int arc, char **arv)
{
	t_stack	*a;
	//t_stack *b;

	a = NULL;
	if((arc == 1) || (arc == 2 && !arv[1][0]))
		return(0);
	else if (arc == 2)
		arv = ft_split(arv[1], ' ');
	else
		arv = &arv[1];
	init_stack(&a, arv);
	if(!stack_sorted(a))
	{
		//debut algo de tri
		write(1, "no", 2);
	}
	else
	{
		write(1, "yes", 3);
	}
	return (0);
}
