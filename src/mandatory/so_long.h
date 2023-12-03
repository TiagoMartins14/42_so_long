/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:06:32 by patatoss          #+#    #+#             */
/*   Updated: 2023/12/03 13:49:55 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define MALLOC_ERR "Error\nUnable to malloc\n"
# define MAP_ERR "Error\nInvalid map\n"

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		size;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char			*row;
	int				height;
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	void	*win;
	void	*mlx;
	t_image	wall;
	t_image	floor;
	t_image	player;
	t_image	collectible;
	t_image	exit;
	t_map	*map;
	char	**map_matrix;
	int		bits_per_pixel;
	int		moves;
	int		total_of_collectibles;
}	t_game;

/* drawmap.c */
void	set_map(t_game *game, int x, int y);
void	draw_map(t_game *game);

/* events.c */
void	win_condition(t_game *game);
void	update_window(t_game *game);
void	game_shutdown(t_game *game);
int		key_press(int keycode, t_game *game);
int		button_press(t_game *game);

/* free_structs.c */
void	delete_list_map(t_map *map);
void	delete_map_array(char **map_array);
void	perror_shutdown(t_game *game, char *str, int map_fd);

/* ft_strndup_inv.c */
char	*ft_strndup_inv(const char *s, size_t n);

/* image_setters.c */
void	set_floor(t_game *game, int x, int y);
void	set_wall(t_game *game, int x, int y);
void	set_player(t_game *game, int x, int y);
void	set_collectible(t_game *game, int x, int y);
void	set_exit(t_game *game, int x, int y);

/* init.c */
t_game	*init(void);
void	image_init(t_image *image);

/* map_checkers.c */
void	count_symbol(char c, int *player, int *collectible, int *exit);
int		all_items_present(t_game *game);
void	is_all_1(t_game *game, t_map *map);
int		check_path(char **map, int x, int y, int collectibles);

/* map_creators.c */
int		map_fd(t_game *game, char *argv);
int		create_map_node(t_game *game, t_map *map, t_map *node, int map_fd);
t_map	*create_map_node_aid(t_game *game, char *temp, int map_fd);
t_map	*map_list(t_game *game, int map_fd);
int		check_map_symbols(char **map_array);
char	**list_to_array(t_game *game, t_map *map);

/* moves.c */
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_back(t_game *game);
void	move_front(t_game *game);

#endif
