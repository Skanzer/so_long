/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:42:20 by szerzeri          #+#    #+#             */
/*   Updated: 2023/04/06 15:08:21 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

static void	ft_write(char c, int *index, int *counter)
{
	write(1, &c, 1);
	*index += 1;
	*counter += 1;
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_convert(va_list args, char c, int *index, int *counter)
{
	*index = *index + 2;
	if (c == 'c')
		*counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*counter += ft_putstring(va_arg(args, char *));
	else if (c == 'p')
		*counter += ft_putpointer(va_arg(args, unsigned long long)) + 2;
	else if (c == 'i' || c == 'd')
		*counter += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*counter += ft_put_unint(va_arg(args, unsigned long long));
	else if (c == 'x')
		*counter += ft_puthex(va_arg(args, unsigned long long), 1);
	else if (c == 'X')
		*counter += ft_puthex(va_arg(args, unsigned long long), 0);
	else if (c == '%')
		*counter += ft_putchar('%');
	else
		*counter = -1 ;
}

int	ft_printf(const char *display, ...)
{
	int			counter;
	int			index;
	va_list		args;

	if (!display)
		return (-1);
	counter = 0;
	index = 0;
	va_start(args, display);
	while (display[index])
	{
		if (display[index] != '%')
			ft_write(display[index], &index, &counter);
		else
		{
			ft_convert(args, display[index + 1], &index, &counter);
			if (counter == -1)
				break ;
		}
	}
	va_end(args);
	return (counter);
}

/*int	main()
{
	int n = -485;
	char *test = "aya %s jet ";

	int counter = ft_printf(test, NULL);
	printf("\n");
	int test1 = printf(test, NULL);
	printf("\n");
	printf(" %i %i", counter, test1);
	printf("\n");
	int test2 = printf(0);
	int test3 = ft_printf(0);
	printf("%i %i", test2, test3);
	return(0);
}*/