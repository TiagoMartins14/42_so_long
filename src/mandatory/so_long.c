/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:49:57 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/22 15:36:51 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game 	game;
	
	if (argc != 2)
		return (1);
	game.map = map_array(map_fd(argv[1]));
	game.map_matrix = list_to_array(game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (ft_strlen(game.map->row) - 1) * 64, game.map->height * 64, "so_long");
	draw_map(&game);
	game.total_of_collectibles = all_items_present(game);
	if (game.total_of_collectibles == 0)
		ft_perror_exit("Error. The map doesn't have all the items needed.\n", 1);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
