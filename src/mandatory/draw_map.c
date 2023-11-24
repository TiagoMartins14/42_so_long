/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:05:06 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/23 11:08:06 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_game *game, int x, int y)
{
	while (game->map)
	{
		x = 0;
		while (game->map->row[x])
		{
			if (game->map->row[x] == '1')
				set_wall(game, x, y);
			else if (game->map->row[x] == '0')
				set_floor(game, x, y);
			else if (game->map->row[x] == 'P')
				set_player(game, x, y);
			else if (game->map->row[x] == 'C')
			{
				set_collectible(game, x, y);
				game->total_of_collectibles++;	
			}
			else if (game->map->row[x] == 'E')
				set_exit(game, x, y);
			x++;
		}
		game->map = game->map->next;
		y++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	t_map	*head;

	head = game->map;
	y = 0;
	x = 0;
	set_map(game, x, y);
	game->map = head;
}
