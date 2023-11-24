/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:07 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/23 10:14:32 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_floor(t_game *game, int x, int y)
{
	game->floor.addr = "./assets/floor.xpm";
	game->floor.size = 64;
	game->floor.x = x * 64;
	game->floor.y = y * 64;
	game->floor.image = mlx_xpm_file_to_image(game->mlx, game->floor.addr, &game->floor.size, &game->floor.size);
	mlx_put_image_to_window(game->mlx, game->win, game->floor.image, game->floor.x, game->floor.y);
}

void	set_wall(t_game *game, int x, int y)
{
	game->wall.addr = "./assets/wall.xpm";
	game->wall.size = 64;
	game->wall.x = x * 64;
	game->wall.y = y * 64;
	game->wall.image = mlx_xpm_file_to_image(game->mlx, game->wall.addr, &game->wall.size, &game->wall.size);
	mlx_put_image_to_window(game->mlx, game->win, game->wall.image, game->wall.x, game->wall.y);
}

void	set_player(t_game *game, int x, int y)
{
	game->player.addr = "./assets/player_front.xpm";
	game->player.size = 64;
	game->player.x = x * 64;
	game->player.y = y * 64;
	game->player.image = mlx_xpm_file_to_image(game->mlx, game->player.addr, &game->player.size, &game->player.size);
	mlx_put_image_to_window(game->mlx, game->win, game->player.image, game->player.x, game->player.y);
}

void	set_collectible(t_game *game, int x, int y)
{
	game->collectible.addr = "./assets/collectible.xpm";
	game->collectible.size = 64;
	game->collectible.x = x * 64;
	game->collectible.y = y * 64;
	game->collectible.image = mlx_xpm_file_to_image(game->mlx, game->collectible.addr, &game->collectible.size, &game->collectible.size);
	mlx_put_image_to_window(game->mlx, game->win, game->collectible.image, game->collectible.x, game->collectible.y);
}

void	set_exit(t_game *game, int x, int y)
{
	game->exit.addr = "./assets/exit.xpm";
	game->exit.size = 64;
	game->exit.x = x * 64;
	game->exit.y = y * 64;
	game->exit.image = mlx_xpm_file_to_image(game->mlx, game->exit.addr, &game->exit.size, &game->exit.size);
	mlx_put_image_to_window(game->mlx, game->win, game->exit.image, game->exit.x, game->exit.y);
}
