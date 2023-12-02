/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:49:57 by patatoss          #+#    #+#             */
/*   Updated: 2023/12/02 16:01:33 by tiago            ###   ########.fr       */
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
	if (is_all_1(game) == 1)
		perror_shutdown(game, NULL, 0);
	game->map_matrix = list_to_array(game, game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (ft_strlen(game->map->row) - 1) * 64, \
											game->map->height * 64, "so_long");
	draw_map(game);
	game->total_of_collectibles = all_items_present(game);
	if (game->total_of_collectibles == 0)
		perror_shutdown(game, NULL, 0);
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
