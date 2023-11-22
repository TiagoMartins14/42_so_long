/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:08 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/21 13:06:45 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_struct_image(t_image *image)
{
	image->image = NULL;
	free(image->addr);
	image->size = 0;
	image->x = 0;
	image->y = 0;
	free(image);
}

void	delete_list_map(t_map *map)
{
	t_map	*temp;

	while(map)
	{
		temp = map;
		free(map->row);
		map->height = 0;
		map = map->next;
		free(temp);
	}
}
void	delete_list_game(t_game *game)
{
	game->win = NULL;
	game->mlx = NULL;
	delete_struct_image(&game->wall);
	delete_struct_image(&game->floor);
	delete_struct_image(&game->player);
	delete_struct_image(&game->collectible);
	delete_struct_image(&game->exit);
	delete_list_map(game->map);
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
	game->moves = 0;
	game->total_of_collectibles = 0;
	free(game);
}
