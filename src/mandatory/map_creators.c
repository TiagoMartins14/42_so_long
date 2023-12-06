/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:58:25 by tiaferna          #+#    #+#             */
/*   Updated: 2023/12/06 07:45:56 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_fd(t_game *game, char *argv)
{
	int		len;
	int		fd_map;
	char	*address;

	len = ft_strlen(argv);
	if (argv[len - 4] != '.' && argv[len -3] != 'b' && \
						argv[len - 2] != 'e' && argv[len - 1] != 'r')
		perror_shutdown(game, NULL, 0);
	address = ft_strjoin("./maps/", argv);
	fd_map = open(address, O_RDONLY);
	free(address);
	if (fd_map == -1)
		perror_shutdown(game, NULL, 0);
	return (fd_map);
}

int	create_map_node(t_game *game, t_map *map, t_map *node, int map_fd)
{
	int		len;
	int		height;
	char	*temp;

	height = 1;
	len = ft_strlen(map->row);
	temp = get_next_line(map_fd);
	while (len && temp)
	{
		if (ft_strlen(temp) != len || temp[0] != '1' \
		|| temp[ft_strlen(temp) - 2] != '1')
		{
			free(temp);
			return (-1);
		}
		map->height = ++height;
		node->next = create_map_node_aid(game, temp, map_fd);
		node = node->next;
		temp = get_next_line(map_fd);
	}
	return (0);
}

t_map	*create_map_node_aid(t_game *game, char *temp, int map_fd)
{
	t_map	*new_node;

	new_node = (t_map *)malloc(sizeof(t_map));
	if (!new_node)
	{
		free(temp);
		perror_shutdown(game, temp, map_fd);
	}
	new_node->row = ft_strdup(temp);
	if (!new_node->row)
	{
		free(temp);
		perror_shutdown(game, temp, map_fd);
	}
	new_node->next = NULL;
	free(temp);
	return (new_node);
}

t_map	*map_list(t_game *game, int map_fd)
{
	t_map	*map;
	t_map	*node;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror_exit(MALLOC_ERR, 1);
	map->next = NULL;
	map->row = get_next_line(map_fd);
	if (map->row == NULL)
		perror_shutdown(game, NULL, map_fd);
	node = map;
	if (create_map_node(game, map, node, map_fd) == -1)
	{
		get_next_line(-1);
		delete_list_map(map);
		perror_shutdown(game, NULL, map_fd);
	}
	close(map_fd);
	is_all_1(game, map);
	return (map);
}

char	**list_to_array(t_game *game, t_map *map)
{
	char	**map_array;
	t_map	*node;
	int		i;

	i = 0;
	node = map;
	map_array = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map_array)
		perror_shutdown(game, NULL, 0);
	while (node)
	{
		map_array[i++] = ft_strndup_inv(node->row, ft_strlen(node->row) - 1);
		if (!map_array[i - 1])
		{
			delete_map_array(map_array);
			perror_shutdown(game, NULL, 0);
		}
		node = node->next;
	}
	map_array[i] = NULL;
	if (check_map_symbols(map_array) == -1)
		perror_shutdown(game, NULL, 0);
	return (map_array);
}
