/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:34:04 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 20:49:18 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsigned(int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else if (nbr < 10)
	{
		nbr = nbr + 48;
		write(1, &(nbr), 1);
		*count += 1;
	}
}
