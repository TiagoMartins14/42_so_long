/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:32:44 by patatoss          #+#    #+#             */
/*   Updated: 2023/06/12 09:11:03 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_text(int fd, char *stash);
char	*ft_strchr(const char *stash, int c);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup_break(char *stash);
char	*refresh_stash(char *stash);
int		ft_strlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

#endif