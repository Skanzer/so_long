/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:41:24 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/13 22:29:27 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0')
		width++;
	if (line[width - 1] == '\n')
		width--;
	return (width);
}

static char	*add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	game->height++;
	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	tmp[game->height] = NULL;
	while (i < game->height - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (line);
}

void	count_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'C')
				game->collectibles++;
			if (game->map[i][j] == 'P')
			{
				game->position.x = i;
				game->position.y = j;
				game->player_count++;
			}
			j++;
		}
		i++;
	}
}

int	read_map(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map_path, O_RDONLY);
	if (!fd)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!add_line(game, line))
		{
			free(line);
			break ;
		}
	}
	close (fd);
	game->height--;
	game->width = get_map_width(game->map[0]);
	count_items(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error:\nWrong number of arguments\n");
		exit (0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	game.map_path = argv[1];
	if (check_file_path(&game) == 0)
	{
		ft_printf("Error:\nInvalid file\n");
		red_cross(&game);
	}
	read_map(&game);
	error_check(&game);
	init_game(&game);
	place_images(&game);
	mlx_hook(game.mlx_win, 17, 1L << 2, red_cross, &game);
	mlx_hook(game.mlx_win, 2, (1L << 0), key_check, &game);
	mlx_loop(game.mlx);
	return (0);
}
