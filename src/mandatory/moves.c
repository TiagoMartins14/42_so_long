/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:25:57 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/29 12:18:45 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	ft_printf("Moves: %d\n", ++(game->moves));
	if (game->map_matrix[game->player.y / 64][game->player.x / 64 + 1] == 'E')
		game->player.addr = "./textures/exit_player_right.xpm";
	else
		game->player.addr = "./textures/player_right.xpm";
	game->player.x += 64;
}

void	move_left(t_game *game)
{
	ft_printf("Moves: %d\n", ++(game->moves));
	if (game->map_matrix[game->player.y / 64][game->player.x / 64 - 1] == 'E')
		game->player.addr = "./textures/exit_player_left.xpm";
	else
		game->player.addr = "./textures/player_left.xpm";
	game->player.x -= 64;
}

void	move_back(t_game *game)
{
	ft_printf("Moves: %d\n", ++(game->moves));
	if (game->map_matrix[game->player.y / 64 - 1][game->player.x / 64] == 'E')
		game->player.addr = "./textures/exit_player_back.xpm";
	else
		game->player.addr = "./textures/player_back.xpm";
	game->player.y -= 64;
}

void	move_front(t_game *game)
{
	ft_printf("Moves: %d\n", ++(game->moves));
	if (game->map_matrix[game->player.y / 64 + 1][game->player.x / 64] == 'E')
		game->player.addr = "./textures/exit_player_front.xpm";
	else
		game->player.addr = "./textures/player_front.xpm";
	game->player.y += 64;
}
