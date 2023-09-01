/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:16:49 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/14 15:30:33 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx-linux/mlx.h"
# include "libft/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define A_UP 65362
# define A_DOWN 65364
# define A_RIGHT 65363
# define A_LEFT 65361

typedef enum e_direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
}	t_direction;

typedef struct s_img {
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_position {
	int	x;
	int	y;
}	t_position;

typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	char		*map_path;
	char		**map;
	int			number_mv;
	int			error;
	int			height;
	int			width;
	int			collectibles;
	int			player_count;
	int			collectible_count;
	int			exit_count;
	int			screen_width;
	int			screen_height;
	t_img		tree;
	t_img		exit;
	t_img		player_up;
	t_img		player_down;
	t_img		player_right;
	t_img		player_left;
	t_img		collectible;
	t_img		grass;
	t_position	position;
}	t_game;

int		check_walls(t_game *game);
int		check_file_path(t_game *game);
int		check_lines(t_game *game);
int		check_rectangular(t_game *game);
int		check_items(t_game *game);
int		check_map(t_game *game);
int		red_cross(t_game *game);
int		read_map(t_game *game);
int		get_map_width(char *line);
int		key_check(int keycode, t_game *game);
int		invalid_path(t_game *vars, int i);
int		invalid_path(t_game *vars, int i);
int		error_exit(t_game *game);
int		check_map_size(t_game *game);
int		flood_fill(t_game *game);
void	free_map(t_game *game);
void	error_check(t_game *game);
void	count_items(t_game *game);
void	put_image(t_game *game, t_img *img, int x, int y);
char	**dup_string_arr(char **original, int length);
void	ft_free(char **to_free);
void	init_game(t_game *game);
void	place_player(t_game *game, int x, int y, t_direction direction );
void	place_images(t_game *game);
void	*init_img(t_game *game, t_img *img);
#endif