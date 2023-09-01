/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:28:42 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/14 13:54:06 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, t_img *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, x, y);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (check_map_size(game) == 0)
		red_cross(game);
	game->mlx_win = mlx_new_window(game->mlx, (game->width * 32), \
	(game->height * 32), "so_long");
	game->tree.relative_path = "./images/tree.xpm";
	game->tree.img = init_img(game, &game->tree);
	game->exit.relative_path = "images/exit.xpm";
	game->exit.img = init_img(game, &game->exit);
	game->player_up.relative_path = "images/player_up.xpm";
	game->player_up.img = init_img(game, &game->player_up);
	game->player_down.relative_path = "images/player_down.xpm";
	game->player_down.img = init_img(game, &game->player_down);
	game->player_right.relative_path = "images/player_right.xpm";
	game->player_right.img = init_img(game, &game->player_right);
	game->player_left.relative_path = "images/player_left.xpm";
	game->player_left.img = init_img(game, &game->player_left);
	game->collectible.relative_path = "images/collectible.xpm";
	game->collectible.img = init_img(game, &game->collectible);
	game->grass.relative_path = "images/grass.xpm";
	game->grass.img = init_img(game, &game->grass);
}

void	place_player(t_game *game, int x, int y, t_direction direction )
{
	if (direction == UP)
		put_image(game, &game->player_up, (y * 32), (x * 32));
	if (direction == DOWN)
		put_image(game, &game->player_down, (y * 32), (x * 32));
	if (direction == RIGHT)
		put_image(game, &game->player_right, (y * 32), (x * 32));
	if (direction == LEFT)
		put_image(game, &game->player_left, (y * 32), (x * 32));
	game->position.x = x;
	game->position.y = y;
}

void	place_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				put_image(game, &game->tree, (j * 32), (i * 32));
			else if (game->map[i][j] == 'P')
				place_player(game, i, j, DOWN);
			else if (game->map[i][j] == 'C')
				put_image(game, &game->collectible, (j * 32), (i * 32));
			else if (game->map[i][j] == 'E')
				put_image(game, &game->exit, (j * 32), (i * 32));
			else if (game->map[i][j] == '0')
				put_image(game, &game->grass, (j * 32), (i * 32));
			j++;
		}
		i++;
	}
}

void	*init_img(t_game *game, t_img *img)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(game->mlx, img->relative_path, \
			&img->img_width, &img->img_height);
	return (tmp);
}
