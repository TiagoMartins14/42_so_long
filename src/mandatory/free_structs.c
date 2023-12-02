/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:08 by patatoss          #+#    #+#             */
/*   Updated: 2023/12/02 16:26:21 by tiago            ###   ########.fr       */
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
	game_shutdown(game);
	ft_perror_exit(MAP_ERR, 1);
}
