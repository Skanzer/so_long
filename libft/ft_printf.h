/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerzeri <szerzeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:00:03 by szerzeri          #+#    #+#             */
/*   Updated: 2023/04/06 14:37:37 by szerzeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *display, ...);
int		ft_putchar(char c);
int		ft_putstring(char *s);
int		ft_puthex(unsigned int hex, int ul);
int		ft_putpointer(unsigned long long hex);
int		ft_putnbr(int n);
int		ft_put_unint(unsigned int n);

#endif