/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:09 by flmuller          #+#    #+#             */
/*   Updated: 2024/04/15 14:05:12 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (free_stash(&stash[fd]));
	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	stash[fd] = readline(fd, stash[fd]);
	line = cutline(stash[fd]);
	if (line)
		stash[fd] = cutstash(stash[fd]);
	else
		free_stash(&stash[fd]);
	return (line);
}

char	*readline(int fd, char *stash)
{
	char	*buffer;
	int		nbcread;

	nbcread = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(stash, '\n') && nbcread > 0)
	{
		nbcread = read(fd, buffer, BUFFER_SIZE);
		buffer[nbcread] = 0;
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

unsigned int	whereendline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}

char	*cutline(char *stash)
{
	char			*line;
	unsigned int	i;

	i = 0;
	line = ft_calloc((whereendline(stash) + 1), sizeof(char));
	while (i < whereendline(stash))
	{
		line[i] = stash[i];
		i++;
	}
	if (ft_strlen(line) < 1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*cutstash(char *stash)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*temp;

	i = whereendline(stash);
	size = ft_strlen(&stash[i]);
	temp = ft_calloc((size + 1), sizeof(char));
	j = 0;
	while (j <= size)
		temp[j++] = stash[i++];
	free(stash);
	stash = NULL;
	if (size == 0)
		free(temp);
	else
		stash = temp;
	return (stash);
}
