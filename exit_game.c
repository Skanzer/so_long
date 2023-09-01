/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:53:16 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/14 21:28:57 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free (game->map);
	(game->map) = NULL;
}

void	ft_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free (to_free);
}

int	red_cross(t_game *game)
{
	if (game->map)
		free_map(game);
	mlx_destroy_image(game->mlx, game->tree.img);
	mlx_destroy_image(game->mlx, game->collectible.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->player_up.img);
	mlx_destroy_image(game->mlx, game->player_down.img);
	mlx_destroy_image(game->mlx, game->player_right.img);
	mlx_destroy_image(game->mlx, game->player_left.img);
	mlx_destroy_image(game->mlx, game->grass.img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}

int	error_exit(t_game *game)
{
	free_map(game);
	exit (0);
}
