/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:49:57 by tiaferna          #+#    #+#             */
/*   Updated: 2023/12/06 07:46:04 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**path_checker;

	if (argc != 2)
		ft_perror_exit("Error\nWrong input\n", 1);
	game = init();
	game->map = map_list(game, map_fd(game, argv[1]));
	game->map_matrix = list_to_array(game, game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (ft_strlen(game->map->row) - 1) * 64, \
											game->map->height * 64, "so_long");
	draw_map(game);
	game->total_of_collectibles = all_items_present(game);
	path_checker = list_to_array(game, game->map);
	if (check_path(path_checker, game->player.x / 64, game->player.y / 64, 0) \
												!= game->total_of_collectibles)
	{
		delete_map_array(path_checker);
		perror_shutdown(game, NULL, 0);
	}
	delete_map_array(path_checker);
	mlx_hook (game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook (game->win, DestroyNotify, 1L << 17, &button_press, game);
	mlx_loop(game->mlx);
	return (0);
}
