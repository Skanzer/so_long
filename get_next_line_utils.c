/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:05:10 by szerzeri          #+#    #+#             */
/*   Updated: 2023/08/11 01:10:21 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strc(char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	while (j < len_s1)
		join[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_join(char *storage, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(storage, buffer);
	free(storage);
	return (tmp);
}

void	ft_set(void *to_set, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)to_set;
	while (i < n)
		str[i++] = '\0';
}
