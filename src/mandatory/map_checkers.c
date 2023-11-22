/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:51:07 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/22 18:32:04 by patatoss         ###   ########.fr       */
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
		i = 0;
		while (game.map->row[i])
		{
			if (game.map->row[i] == 'P')
				player++;
			else if (game.map->row[i] == 'C')
				collectible++;
			else if (game.map->row[i] == 'E')
				exit++;
			i++;
		}
		game.map = game.map->next;
	}
	if (game.player.x == 0 || game.collectible.x == 0 || game.exit.x == 0)
		return (0);
	return (collectible);
}

int	map_fd(char *argv)
{
	int		fd_map;
	char	*address;
	
	address = ft_strjoin("./maps/", argv);
	fd_map = open(address, O_RDONLY);
	free(address);
	if (fd_map == -1)
	{
		perror("fd error.\n");
		exit(0);
	}
	return (fd_map);
}

// int	is_all_1()

t_map	*map_array(int map_fd)
{
	t_map	*map;
	t_map	*node;
	char	*temp;
	int		len;
	int		height;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->next = NULL;
	map->row = get_next_line(map_fd);
	if (map->row == NULL)
	{
		free(map);
		ft_perror_exit("Invalid map size.\n", 1);
	}
	len = ft_strlen(map->row);
	node = map;
	height = 1;
	while (len)
	{
		temp = get_next_line(map_fd);
		if (temp == NULL)
			break;
		if (ft_strlen(temp) != len || temp[0] != '1' || temp[ft_strlen(temp) - 2] != '1')
		{
			free(temp);
			delete_list_map(map);
			ft_perror_exit("Invalid map.\n", 1);
		}
		map->height = ++height;
		node->next = (t_map *)malloc(sizeof(t_map));
		node = node->next;
		node->row = ft_strdup(temp);
		node->next = NULL;
		free(temp);
	}
	return (map);	
}

void	draw_map(t_game *game)
{
	int	i;
	int	x;
	int	y;
	t_map	*head;

	head = game->map;
	y = 0;
	while (game->map)
	{
		i = 0;
		x = 0;
		while (game->map->row[i])
		{
			if (game->map->row[i] == '1')
				set_wall(game, x, y);
			else if (game->map->row[i] == '0')
				set_floor(game, x, y);
			else if (game->map->row[i] == 'P')
				set_player(game, x, y);
			else if (game->map->row[i] == 'C')
			{
				set_collectible(game, x, y);
				game->total_of_collectibles++;	
			}
			else if (game->map->row[i] == 'E')
				set_exit(game, x, y);
			i++;
			x++;
		}
		game->map = game->map->next;
		y++;
	}
	game->map = head;
}

char	**list_to_array(t_map *map)
{
	char	**map_array;
	t_map	*node;
	int		i;
	
	i = 0;
	node = map;
	map_array = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map_array)
		return (NULL);
	while (node)
	{
		map_array[i++] = ft_strndup_inv(node->row, ft_strlen(node->row) - 1);
		if (!map_array[i - 1])
		{
			delete_list_map(map);
			ft_perror_exit("Unable to allocate memory.\n", 1);
		}
		node = node->next;
	}
	map_array[i] = NULL;
	return (map_array);
}
