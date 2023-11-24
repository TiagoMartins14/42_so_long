/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:06:32 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/24 17:12:15 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../../mlx_linux/mlx.h"
# include <fcntl.h>

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		size;
	int		x;
	int		y;
} t_image;

typedef struct s_map
{
	char			*row;
	int				height;
	struct s_map	*next;
} t_map;

typedef struct s_game
{
	void	*win;
	void	*mlx;
	t_image	wall;
	t_image	floor;
	t_image player;
	t_image	collectible;
	t_image	exit;
	t_map	*map;
	char	**map_matrix;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		moves;
	int		total_of_collectibles;
} t_game;

/* map_checkers.c */
int		all_items_present(t_game game);
int		is_all_1(t_game game);
int		map_fd(char *argv);
int		check_path(char **map, int x, int y, int collectibles);


/* map_creators.c */
int		map_fd(char *argv);
void	create_map_node(t_map *map, t_map *node, int map_fd);
t_map	*map_list(int map_fd);
char	**list_to_array(t_map *map);

/* drawmap.c */
void	set_map(t_game *game, int x, int y);
void	draw_map(t_game *game);

/* events.c */
void	win_condition(t_game *game);
void	update_window(t_game *game);
int		key_press(int keycode, t_game *game);

/* moves.c */
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_back(t_game *game);
void	move_front(t_game *game);

/* image_setters.c */
void	set_floor(t_game *game, int x, int y);
void	set_wall(t_game *game, int x, int y);
void	set_player(t_game *game, int x, int y);
void	set_collectible(t_game *game, int x, int y);
void	set_exit(t_game *game, int x, int y);

/* free_structs.c */
void	delete_struct_image(t_image *image);
void	delete_list_map(t_map *map);
void	delete_map_array(char **map_array);
void	perror_free_str_map_fd(char *str, t_map *map, char *msg, int map_fd);

/* ft_strndup_inv.c */
char	*ft_strndup_inv(const char *s, size_t n);
#endif
