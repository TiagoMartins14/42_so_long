/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:58:28 by patatoss          #+#    #+#             */
/*   Updated: 2023/06/12 09:09:10 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_text(int fd, char *stash)
{
	char	*buffer;
	int		read_val;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_val = 1;
	while (read_val != 0 && !ft_strchr(stash, '\n'))
	{
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[read_val] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_text(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_strdup_break(stash);
	stash = refresh_stash(stash);
	return (line);
}
