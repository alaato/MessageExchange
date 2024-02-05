/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:19:41 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 20:50:49 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		*count += 1;
		ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else if (n >= 0 && n < 10)
	{
		n = n + 48;
		write(1, &(n), 1);
		*count += 1;
	}
}
