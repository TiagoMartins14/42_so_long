/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:08 by tiaferna          #+#    #+#             */
/*   Updated: 2023/12/06 07:45:42 by tiaferna         ###   ########.fr       */
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

void	perror_shutdown(t_game *game, char *str, int map_fd)
{
	if (str)
		free(str);
	if (map_fd)
		close(map_fd);
	write(2, MAP_ERR, ft_strlen(MAP_ERR));
	game_shutdown(game);
}
