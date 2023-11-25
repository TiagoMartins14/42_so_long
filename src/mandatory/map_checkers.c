/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:51:07 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/25 12:17:59 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_items_present(t_game game)
{
	int	i;
	int	player;
	int	collectible;
	int	exit;

	player = 0;
	collectible = 0;
	exit = 0;
	while (game.map)
	{
		i = -1;
		while (game.map->row[++i])
		{
			if (game.map->row[i] == 'P')
				player++;
			else if (game.map->row[i] == 'C')
				collectible++;
			else if (game.map->row[i] == 'E')
				exit++;
		}
		game.map = game.map->next;
	}
	if (player != 1 || collectible == 0 || exit != 1)
		return (0);
	return (collectible);
}

int	is_all_1(t_game game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game.map->row) - 1)
		if (game.map->row[i++] != '1')
			return (1);
	while (game.map->next)
		game.map = game.map->next;
	i = 0;
	while (i < ft_strlen(game.map->row) - 1)
		if (game.map->row[i++] != '1')
			return (1);
	return (0);
}

int	check_path(char **map, int x, int y, int collectibles)
{
	if (map[y][x] == 'C')
		collectibles++;
	map[y][x] = 'F';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		collectibles = check_path(map, x + 1, y, collectibles);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		collectibles = check_path(map, x - 1, y, collectibles);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		collectibles = check_path(map, x, y + 1, collectibles);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		collectibles = check_path(map, x, y - 1, collectibles);
	return (collectibles);
}
