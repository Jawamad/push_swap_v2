/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:29 by florian           #+#    #+#             */
/*   Updated: 2024/04/15 13:53:32 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include "push_swap.h"

/* checker.c */

void			execsort(t_stack **a, t_stack **b);
void			execline(t_stack **a, t_stack **b, char *line);
void			write_sort_res(t_stack *a);

/* get_next_line.c */
char			*get_next_line(int fd);
char			*readline(int fd, char *stash);
unsigned int	whereendline(char *stash);
char			*cutline(char *stash);
char			*cutstash(char *stash);

/* get_next_line_utils.c */
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*free_stash(char **stash);

#endif