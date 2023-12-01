/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:08:56 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/30 20:07:30 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_perror_exit("Error\nMalloc error\n", 1);
	game->win = NULL;
	game->mlx = NULL;
	game->map_matrix = NULL;
	game->bits_per_pixel = 0;
	game->moves = 0;
	game->total_of_collectibles = 0;
	image_init(&game->wall);
	image_init(&game->floor);
	image_init(&game->player);
	image_init(&game->collectible);
	image_init(&game->exit);
	game->map = NULL;
	return (game);
}

void	image_init(t_image *image)
{
	image->addr = NULL;
	image->size = 0;
	image->x = 0;
	image->y = 0;
	image->image = NULL;
}
