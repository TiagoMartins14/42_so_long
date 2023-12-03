/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:51:07 by patatoss          #+#    #+#             */
/*   Updated: 2023/12/03 13:50:25 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_symbol(char c, int *player, int *collectible, int *exit)
{
	if (c == 'P')
		(*player)++;
	else if (c == 'C')
		(*collectible)++;
	else if (c == 'E')
		(*exit)++;
}

int	all_items_present(t_game *game)
{
	int		i;
	int		player;
	int		collectible;
	int		exit;
	t_map	*node;

	player = 0;
	collectible = 0;
	exit = 0;
	node = game->map;
	while (node)
	{
		i = -1;
		while (node->row[++i])
			count_symbol(node->row[i], &player, &collectible, &exit);
		node = node->next;
	}
	if (player != 1 || collectible == 0 || exit != 1)
		perror_shutdown(game, NULL, 0);
	return (collectible);
}

void	is_all_1(t_game *game, t_map *map)
{
	int		i;
	t_map	*node;

	i = 0;
	node = map;
	while (i < ft_strlen(node->row) - 1)
	{
		if (node->row[i++] != '1')
		{
			delete_list_map(map);
			perror_shutdown(game, NULL, 0);
		}
	}
	while (node->next)
		node = node->next;
	i = 0;
	while (i < ft_strlen(node->row) - 1)
	{
		if (node->row[i++] != '1')
		{
			delete_list_map(map);
			perror_shutdown(game, NULL, 0);
		}
	}
	return ;
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

int	check_map_symbols(char **map_array)
{
	int	x;
	int	y;

	y = 0;
	while (map_array[y])
	{
		x = 0;
		while (map_array[y][x])
		{
			if (map_array[y][x] != 'P' && map_array[y][x] != 'C' && \
			map_array[y][x] != 'E' && map_array[y][x] != '1' && \
			map_array[y][x] != '0')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
