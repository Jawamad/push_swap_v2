/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:31:19 by florian           #+#    #+#             */
/*   Updated: 2024/04/15 15:35:58 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/checker.h"

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
	execsort(&a, &b);
	write_sort_res(a);
	free_stack(&a, arv, 0);
	if (err_code == 1)
		free_arv(arv);
	return (0);
}

void	execsort(t_stack **a, t_stack **b)
{
	char	*line;
	line = get_next_line(0);
	while (line != NULL)
	{
		execline(a, b, line);
		line = get_next_line(0);
	}
}

void	execline(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rrotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		double_move(a, b, rotate, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		double_move(a, b, rrotate, 0);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		double_move(a, b, swap, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(b, a);
	else
		write(2, "Error\n", 6);
	free(line);
}

void	write_sort_res(t_stack *a)
{
	if (stack_sorted(a))
		write(2, "OK\n", 3);
	else if (!stack_sorted(a))
		write(2, "KO\n", 3);
}
