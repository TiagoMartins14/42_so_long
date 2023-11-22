/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_inv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:39:19 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/21 23:41:49 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strndup_inv(const char *s, size_t n)
{
	size_t	i;
	char	*s_dup;

	i = 0;
	while (s[i])
		i++;
	s_dup = malloc(sizeof(char) * n + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
