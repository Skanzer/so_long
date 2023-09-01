/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:29:08 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/14 15:33:03 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**dup_string_arr(char **original, int length)
{
	int		i;
	char	**new;
	int		len;

	i = 0;
	new = malloc((length + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (i < length)
	{
		len = ft_strlen(original[i]) + 1;
		new[i] = malloc(len * sizeof(char));
		if (new[i] == NULL)
		{
			ft_free(new);
			return (NULL);
		}
		ft_strlcpy(new[i], original[i], len);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	flood(char **map, int x, int y, t_game *game)
{
	while (map[x][y] != '1' && map[x][y] != 'X')
	{
		if (map[x][y] == 'C')
			game->collectible_count--;
		else if (map[x][y] == 'E')
			game->exit_count--;
		map[x][y] = 'X';
		flood(map, x + 1, y, game);
		flood(map, x - 1, y, game);
		flood(map, x, y + 1, game);
		flood(map, x, y - 1, game);
	}
}

/*Creates a copy of the map and floods it starting from the player, until 
it has nowhere to go due to walls/exit blocking the way. Then, checks if 
all of the collectibles have been collected and if the exit have been
found, meaning there is a valid path to all of them.*/
int	flood_fill(t_game *game)
{
	t_game	dup;

	ft_memset(&dup, 0, sizeof(t_game));
	dup.map = dup_string_arr(game->map, game->height);
	dup.player_count = game->player_count;
	dup.collectible_count = game->collectibles;
	dup.exit_count = game->exit_count;
	dup.width = game->width;
	dup.height = game->height;
	dup.position.x = game->position.x;
	dup.position.y = game->position.y;
	flood(dup.map, dup.position.x, dup.position.y, &dup);
	free_map(&dup);
	if (dup.collectible_count != 0 || dup.exit_count != 0)
	{
		game->error = 1;
		return (0);
	}
	return (1);
}
