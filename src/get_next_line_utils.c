/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:05 by flmuller          #+#    #+#             */
/*   Updated: 2024/04/15 14:05:14 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	unsigned int	tsize;
	unsigned int	i;

	tsize = nmemb * size;
	if (!nmemb || !size)
		return (malloc(0));
	if (tsize / size != nmemb || tsize / nmemb != size)
		return (0);
	res = malloc(tsize);
	if (res)
	{
		i = 0;
		while (i < tsize)
		{
			res[i] = '\0';
			i++;
		}
	}
	return ((void *)res);
} */

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*newstr;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen((char *) s1) + ft_strlen((char *)s2) + 1;
	newstr = malloc(sizeof(char) * size);
	if (newstr)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			newstr[i + j] = s2[j];
			j++;
		}
		newstr[i + j] = '\0';
	}
	free(s1);
	return (newstr);
}

char	*free_stash(char **stash)
{
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (0);
}
