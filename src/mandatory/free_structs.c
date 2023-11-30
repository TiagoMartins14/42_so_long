/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:08 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/30 11:53:46 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_list_map(t_map *map)
{
	t_map	*temp;

	while (map)
	{
		temp = map;
		free(map->row);
		map->height = 0;
		map = map->next;
		free(temp);
	}
}

void	delete_map_array(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
		free(map_array[i++]);
	free(map_array);
}

void	perror_free_str_map_fd(char *str, t_map *map, char *msg, int map_fd)
{
	if (str)
		free(str);
	if (map)
		delete_list_map(map);
	if (map_fd)
		close(map_fd);
	ft_perror_exit(msg, 1);
	return ;
}

void	perror_shutdown(t_game *game)
{
	game_shutdown(game);
	ft_perror_exit(MAP_ERR, 1);
}
