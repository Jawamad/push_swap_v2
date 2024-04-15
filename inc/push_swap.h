/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:28:53 by florian           #+#    #+#             */
/*   Updated: 2024/04/11 14:51:06 by florian          ###   ########.fr       */
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
	int				value;
	int				index;
	int				push_cost;
	int				cheapest;
	int				above_median;
	struct s_stack	*next;
	struct s_stack	*target_node;
}	t_stack;

/* parse */
void	init_stack(t_stack **a, char **arv, int err_code);
int		check_syntax(char *arv);
int		check_dupli(t_stack *stack, int value);

/*node_control*/
void	add_node(t_stack **stack, int value);
void	set_target(t_stack *node, t_stack *st_target);
void	set_reverse_target(t_stack *node, t_stack *st_target);
void	reset_attribute(t_stack *stack);
void	set_cheapest(t_stack *stack);

/* utils */
long	ft_atol(const char *nptr);
int		free_stack(t_stack **stack, char **arv, int err_code);
void	free_arv(char **arv);
void	ft_stackadd_front(t_stack **lst, t_stack *new);

/* stack_checker */
int		stack_lenght(t_stack *stack);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*lnode_finder(t_stack *stack);
t_stack	*find_lowest(t_stack *stack);

/* move_write */
void	double_move(t_stack **a, t_stack **b, void (*f)(t_stack **), int move);
void	simple_move(t_stack **stack, void (*f)(t_stack **), int move);
void	push_move(t_stack **stack_1, t_stack **stack_2, int move);

/* move */
void	swap(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

/* sort */
void	sort(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	min_rotate(t_stack **a);
int		stack_sorted(t_stack *stack);

/* rotate_and_push */
void	rotate_to_move(t_stack **a, t_stack **b);
void	double_rotate(t_stack **a, t_stack **b, t_stack	*cheapest, int dir);
void	push_b_to_a(t_stack **a, t_stack **b);
void	latests_rotate(t_stack **stack, t_stack *node, int move);

/* reset */
void	reset_a(t_stack **a, t_stack **b);
void	reset_b(t_stack **a, t_stack **b);
void	calc_push_cost(t_stack *tmpa, t_stack *a, t_stack *b);
#endif