/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:17:13 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/22 15:05:30 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115)
	{
		ft_printf("%d\n", ++(game->moves));
		game->floor.x = game->player.x;
		game->floor.y = game->player.y;
		if (game->map_matrix[game->player.y / 64][game->player.x / 64] == 'E')
			game->floor.addr = "./assets/exit.xpm";
		else
			game->floor.addr = "./assets/floor.xpm";
		if (keycode ==  100 && game->map_matrix[game->player.y / 64][game->player.x / 64 + 1] != '1')
		{
			if (game->map_matrix[game->player.y / 64][game->player.x / 64 + 1] == 'E')
				game->player.addr = "./assets/exit_player_right.xpm";
			else
				game->player.addr = "./assets/player_right.xpm";
			game->player.x += 64;
		}
		if (keycode ==  97 && game->map_matrix[game->player.y / 64][game->player.x / 64 - 1] != '1')
		{
			if (game->map_matrix[game->player.y / 64][game->player.x / 64 - 1] == 'E')
				game->player.addr = "./assets/exit_player_left.xpm";
			else
				game->player.addr = "./assets/player_left.xpm";
			game->player.x -= 64;
		}
		if (keycode ==  119 && game->map_matrix[game->player.y / 64 - 1][game->player.x / 64] != '1')
		{
			if (game->map_matrix[game->player.y / 64 - 1][game->player.x / 64] == 'E')
				game->player.addr = "./assets/exit_player_back.xpm";
			else
				game->player.addr = "./assets/player_back.xpm";
			game->player.y -= 64;
		}
		if (keycode ==  115 && game->map_matrix[game->player.y / 64 + 1][game->player.x / 64] != '1')
		{
			if (game->map_matrix[game->player.y / 64 + 1][game->player.x / 64] == 'E')
				game->player.addr = "./assets/exit_player_front.xpm";
			else
				game->player.addr = "./assets/player_front.xpm";
			game->player.y += 64;
		}
		game->player.image = mlx_xpm_file_to_image(game->mlx, game->player.addr, &game->player.size, &game->player.size);
		game->floor.image = mlx_xpm_file_to_image(game->mlx, game->floor.addr, &game->floor.size, &game->floor.size);
		mlx_put_image_to_window(game->mlx, game->win, game->floor.image, game->floor.x, game->floor.y);
		mlx_put_image_to_window(game->mlx, game->win, game->player.image, game->player.x, game->player.y);
		if (game->map_matrix[game->player.y / 64][game->player.x / 64] == 'C')
		{
			game->total_of_collectibles -= 1;
			game->map_matrix[game->player.y / 64][game->player.x / 64] = '0';
		}
		if (game->map_matrix[game->player.y / 64][game->player.x / 64] == 'E' && game->total_of_collectibles == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	return (0);
}
