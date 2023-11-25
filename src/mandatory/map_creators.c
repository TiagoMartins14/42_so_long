/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:58:25 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/25 11:57:36 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_fd(char *argv)
{
	int		fd_map;
	char	*address;

	address = ft_strjoin("./maps/", argv);
	fd_map = open(address, O_RDONLY);
	free(address);
	if (fd_map == -1)
		ft_perror_exit("fd error.\n", 1);
	return (fd_map);
}

void	create_map_node(t_map *map, t_map *node, int map_fd)
{
	int		len;
	int		height;
	char	*temp;

	len = ft_strlen(map->row);
	height = 1;
	while (len)
	{
		temp = get_next_line(map_fd);
		if (temp == NULL)
			break ;
		if (ft_strlen(temp) != len || temp[0] != '1' || \
										temp[ft_strlen(temp) - 2] != '1')
			perror_free_str_map_fd(temp, map, "Invalid map.\n", map_fd);
		map->height = ++height;
		node->next = (t_map *)malloc(sizeof(t_map));
		if (node->next == NULL)
			perror_free_str_map_fd(temp, map, "Invalid map.\n", map_fd);
		node = node->next;
		node->row = ft_strdup(temp);
		if (node->row == NULL)
			perror_free_str_map_fd(temp, map, "Invalid map.\n", map_fd);
		node->next = NULL;
		free(temp);
	}
}

t_map	*map_list(int map_fd)
{
	t_map	*map;
	t_map	*node;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror_exit("Unable to allocate memory.\n", 1);
	map->next = NULL;
	map->row = get_next_line(map_fd);
	if (map->row == NULL)
		perror_free_str_map_fd(NULL, map, \
									"Unable to allocate memory.\n", map_fd);
	node = map;
	create_map_node(map, node, map_fd);
	close(map_fd);
	return (map);
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
				return (1);
			x++;
		}
		y++;
	}
	return (0);
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
		perror_free_str_map_fd(NULL, map, "Unable to allocate memory.\n", 0);
	while (node)
	{
		map_array[i++] = ft_strndup_inv(node->row, ft_strlen(node->row) - 1);
		if (!map_array[i - 1])
		{
			delete_map_array(map_array);
			perror_free_str_map_fd(NULL, map, \
											"Unable to allocate memory.\n", 0);
		}
		node = node->next;
	}
	map_array[i] = NULL;
	if (check_map_symbols(map_array) == 1)
		perror_free_str_map_fd(NULL, map, "Invalid map.\n", 0);
	return (map_array);
}
