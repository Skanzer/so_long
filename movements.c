/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:41:05 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/13 17:05:00 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_exit(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'E')
	{
		if (game->collectible_count == game->collectibles)
		{
			ft_printf("Congrats, you won !!");
			red_cross(game);
		}
	}
}

void	move(t_game *game, int x, int y, t_direction direction)
{
	int	i;
	int	j;

	i = game->position.y;
	j = game->position.x;
	if (game->map[x][y] != '1')
	{
		game->number_mv++;
		ft_printf("number of moves till now: %i\n", game->number_mv);
		if (game->map[game->position.x][game->position.y] == 'E')
			put_image(game, &game->exit, i * 32, j * 32);
		else
			put_image(game, &game->grass, i * 32, j * 32);
		place_player(game, x, y, direction);
		game->position.x = x;
		game->position.y = y;
	}
	if (game->map[x][y] == 'C')
	{
		game->map[x][y] = '0';
		game->collectible_count++;
	}
	check_exit(game, x, y);
}

int	key_check(int keycode, t_game *game)
{
	if (keycode == ESC)
		red_cross(game);
	if (keycode == S || keycode == A_DOWN)
		move(game, game->position.x + 1, game->position.y, DOWN);
	if (keycode == W || keycode == A_UP)
		move(game, game->position.x - 1, game->position.y, UP);
	if (keycode == D || keycode == A_RIGHT)
		move(game, game->position.x, game->position.y + 1, RIGHT);
	if (keycode == A || keycode == A_LEFT)
		move(game, game->position.x, game->position.y - 1, LEFT);
	return (0);
}
