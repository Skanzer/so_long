/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:25:30 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/14 21:09:48 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] == '1' && game->map[game->height - 1][i] == '1')
			i++;
		else
		{
			game->error = 1;
			return (0);
		}
	}
	i = 1;
	while (i < game->height - 1)
	{
		if (game->map[i][0] == '1' && game->map[i][game->width - 1] == '1')
			i++;
		else
		{
			game->error = 1;
			return (0);
		}
	}
	return (1);
}

int	check_lines(t_game *game)
{
	int	i;
	int	result;

	i = 1;
	while (i < game->height)
	{
		result = 0;
		while (game->map[i][result] != '\0')
			result++;
		if (game->map[i][result - 1] == '\n')
			result--;
		if (result != game->width)
		{
			game->error = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_rectangular(t_game *game)
{
	if (game->height == game->width)
	{
		game->error = 1;
		return (0);
	}
	else
		return (1);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'E' &&
					game->map[i][j] != 'P' &&
					game->map[i][j] != '1' &&
					game->map[i][j] != '0' &&
					game->map[i][j] != 'C' &&
					game->map[i][j] != '\n')
			{
				game->error = 1;
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	check_items(t_game *game)
{
	if (game->exit_count != 1)
	{
		game->error = 1;
		return (0);
	}
	if (game->player_count != 1)
	{
		game->error = 1;
		return (0);
	}
	if (game->collectibles < 1)
	{
		game->error = 1;
		return (0);
	}
	return (1);
}
