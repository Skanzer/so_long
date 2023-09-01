/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:25:53 by szerzeri          #+#    #+#             */
/*   Updated: 2023/04/06 15:08:00 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *s)
{
	int		counter;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	counter = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		counter++;
	}
	return (counter);
}

int	ft_puthex(unsigned int hex, int ul)
{
	int		counter;
	char	c;

	counter = 0;
	if (ul == 1)
		c = 'a';
	else
		c = 'A';
	if (hex >= 16)
	{
		counter += ft_puthex((hex / 16), ul);
		if (hex % 16 > 9)
			counter += ft_putchar(c + ((hex % 16) - 10));
		else
			counter += ft_putchar('0' + (hex % 16));
	}
	else
	{
		if (hex > 9)
			counter += ft_putchar(c + (hex - 10));
		else
			counter += ft_putchar('0' + hex);
	}
	return (counter);
}

int	ft_putpointer(unsigned long long hex)
{
	int	counter;

	if (!hex)
	{
		write(1, "(nil)", 5);
		return (3);
	}
	counter = 0;
	if (hex >= 16)
	{
		counter += ft_putpointer((hex / 16));
		if (hex % 16 > 9)
			counter += ft_putchar('a' + ((hex % 16) - 10));
		else
			counter += ft_putchar('0' + (hex % 16));
	}
	else
	{
		write (1, "0x", 2);
		if (hex > 9)
			counter += ft_putchar('a' + (hex - 10));
		else
			counter += ft_putchar('0' + hex);
	}
	return (counter);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
		counter += ft_putstring("-2147483648");
	else if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}

int	ft_put_unint(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 10)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}
