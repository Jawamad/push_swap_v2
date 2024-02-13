/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:28:53 by florian           #+#    #+#             */
/*   Updated: 2024/02/13 17:33:36 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int 			value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*target_node;
}	t_stack;

/* parse */
void	init_stack(t_stack **a, char **arv);
int		check_syntax(char *arv);
int		check_dupli(t_stack *stack, int value);


/*node_control*/
void	add_node(t_stack **stack, int value);

/* utils */
long	ft_atol(const char *nptr);
int	free_stack(t_stack **stack, char **arv, int code_err);
void	free_arv(char **arv);

/* stack_checker */
int		stack_sorted(t_stack *stack);

/* node_control */
t_stack	*lnode_finder(t_stack *stack);

#endif