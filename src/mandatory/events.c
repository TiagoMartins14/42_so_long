/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:17:13 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/24 19:41:59 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_condition(t_game *game)
{
	if (game->map_matrix[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->total_of_collectibles -= 1;
		game->map_matrix[game->player.y / 64][game->player.x / 64] = '0';
	}
	if (game->map_matrix[game->player.y / 64][game->player.x / 64] == 'E' && game->total_of_collectibles == 0)
	{
		ft_printf("\nCongrats! You won!\n\n");
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
}

void	update_window(t_game *game)
{
	game->player.image = mlx_xpm_file_to_image(game->mlx, game->player.addr, &game->player.size, &game->player.size);
	game->floor.image = mlx_xpm_file_to_image(game->mlx, game->floor.addr, &game->floor.size, &game->floor.size);
	mlx_put_image_to_window(game->mlx, game->win, game->floor.image, game->floor.x, game->floor.y);
	mlx_put_image_to_window(game->mlx, game->win, game->player.image, game->player.x, game->player.y);
	win_condition(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115)
	{
		game->floor.x = game->player.x;
		game->floor.y = game->player.y;
		if (game->map_matrix[game->player.y / 64][game->player.x / 64] == 'E')
			game->floor.addr = "./assets/exit.xpm";
		else
			game->floor.addr = "./assets/floor.xpm";
		if (keycode ==  100 && game->map_matrix[game->player.y / 64][game->player.x / 64 + 1] != '1')
			move_right(game);
		if (keycode ==  97 && game->map_matrix[game->player.y / 64][game->player.x / 64 - 1] != '1')
			move_left(game);
		if (keycode ==  119 && game->map_matrix[game->player.y / 64 - 1][game->player.x / 64] != '1')
			move_back(game);
		if (keycode ==  115 && game->map_matrix[game->player.y / 64 + 1][game->player.x / 64] != '1')
			move_front(game);
		update_window(game);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		delete_map_array(game->map_matrix);
		perror_free_str_map_fd(NULL, game->map, NULL, 0);
	}
	return (0);
}
