/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:29:39 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 20:38:59 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setaddress(unsigned long num, int format, int *count)
{
	if (num >= 16)
	{
		setaddress(num / 16, format, count);
		setaddress(num % 16, format, count);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'), count);
		else
		{
			if (format == 0)
				ft_putchar((num - 10 + 'a'), count);
			if (format == 1)
				ft_putchar((num - 10 + 'A'), count);
		}
	}
}

void	ft_putadress(unsigned long n, int *count)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		setaddress(n, 0, count);
	}
}
