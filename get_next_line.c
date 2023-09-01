/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:55:10 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/11 01:10:20 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t how_much, size_t how_big)
{
	char	*ret;

	ret = malloc(how_much * how_big);
	if (!ret)
		return (NULL);
	ft_set(ret, how_much * how_big);
	return (ret);
}

static char	*update_storage(char *storage)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage[i])
	{
		free (storage);
		return (NULL);
	}
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(storage) - i + 1), sizeof(char));
	i++;
	while (storage[i])
		tmp[j++] = storage[i++];
	free (storage);
	return (tmp);
}

static char	*get_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*get_read(int fd, char *storage)
{
	char	*buffer;
	int		number_byte;

	if (!storage)
		storage = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	number_byte = 1;
	while (number_byte > 0)
	{
		number_byte = read(fd, buffer, BUFFER_SIZE);
		if (number_byte == -1)
		{
			free (buffer);
			free(storage);
			return (NULL);
		}
		buffer[number_byte] = '\0';
		storage = ft_join(storage, buffer);
		if (ft_strc(buffer, '\n') != -1)
			break ;
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage;
	char			*line;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	storage = get_read(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = update_storage(storage);
	return (line);
}

/*int	main()
{
	int	fd;
	char	*test;

	fd = open("read_error.txt", O_RDONLY);

	test = get_next_line(fd);
	printf("*1* %s", test);
	free (test);
	test = get_next_line(fd);
	printf("*2* %s", test);
	free (test);
	close(fd);
	test = get_next_line(fd);
	printf("*after closing* %s", test);
	free (test);
	fd = open("read_error.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("*new 1* %s", test);
	free (test);
	close(fd);
	// test = get_next_line(fd);
	// printf("*1* %s", test);
	// free (test);
	// test = get_next_line(fd);
	// printf("*2* %s", test);
	// 	free (test);
	// do {
	// 	test = get_next_line(fd);
	// 	free(test);
	// } while (test != NULL);
	// test = get_next_line(fd);
	// printf("*3* %s \n", test);
	// free (test);
	// close (fd);
	// fd = open("read_error.txt", O_RDONLY);
	// test = get_next_line(fd);
	// printf("*4* %s", test);
	// free (test);
	// test = get_next_line(fd);
	// printf("*5* %s", test);
	// 	free (test);
	// test = get_next_line(fd);
	// printf("*6* %s", test);
	// 	free (test);
	// test = get_next_line(fd);
	// printf("*7* %s", test);
	// 	free (test);
	// test = get_next_line(fd);
	// printf("*8* %s \n", test);
	// free (test);
	return (0);
}*/