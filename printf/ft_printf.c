/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:32:13 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/14 18:43:24 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_format(const char *fmt, int i, int *count, va_list args)
{
	if (fmt[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (fmt[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (fmt[i] == 'x')
		ft_print_hex(va_arg(args, int), 0, count);
	else if (fmt[i] == 'X')
		ft_print_hex(va_arg(args, int), 1, count);
	else if (fmt[i] == 'p')
		ft_putadress((unsigned long)va_arg(args, void *), count);
	else if (fmt[i] == '%')
		ft_putchar('%', count);
	else if (fmt[i] == 'u')
		put_unsigned(va_arg(args, int), count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (!*fmt)
		return (-1);
	va_start(args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			count++;
			continue ;
		}
		if (fmt[i] == '%')
		{
			i++;
			print_format(fmt, i, &count, args);
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {

// 	return (0);
// }
