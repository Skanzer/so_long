/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:24:11 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/14 21:41:04 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_path(t_game *game)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (game->map_path[i])
	{
		if (game->map_path[i] == '.')
		{
			tmp = ft_substr(game->map_path, i, 4);
			break ;
		}
		i++;
	}
	i = ft_strncmp(tmp, ".ber", 4);
	free(tmp);
	if (i == 0)
		return (1);
	else
	{
		game->error = 1;
		return (0);
	}
}

int	check_map_size(t_game *game)
{
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if ((game->height * 32) > game->screen_height)
		return (0);
	if ((game->width * 32) > game->screen_width)
		return (0);
	return (1);
}

void	error_check(t_game *game)
{
	if (check_walls(game) == 0)
		ft_printf("Error:\nMap invalid: Missing walls\n");
	else if (check_lines(game) == 0)
		ft_printf("Error:\nMap invalid: Width not the same everywhere\n");
	else if (check_rectangular(game) == 0)
		ft_printf("Error:\nMap invalid: Map is not rectangular\n");
	else if (check_map(game) == 0)
		ft_printf("Error:\nMap invalid: Items issue\n");
	else if (check_items(game) == 0)
		ft_printf("Error:\nMap invalid: Wrong number of items\n");
	else if (flood_fill(game) == 0)
		ft_printf("Error:\nMap invalid: Not playable\n");
	if (game->error == 1)
		error_exit(game);
}
