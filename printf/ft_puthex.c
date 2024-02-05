/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:27:48 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 21:19:41 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_puthex(long n, int sign ,int* sum)
// {
//     char hex[16] = "0123456789abcdef";
//     char hex_up[16] = "0123456789ABCDEF";
//     char result[32];
//     unsigned long nbr;
//     int count;

//     nbr = n;
//     count = 0;
//     while((nbr) && ((nbr = nbr / 16) )> 0)
//         count++;
//     nbr = n;
//     result[++count] = 0;
//     while(nbr > 0){
//         if(sign == 0)
//             result[--count] = hex[nbr%16];
//         else
//             result[--count] = hex_up[nbr%16];
//         nbr = nbr / 16;
//     }
// 	ft_putstr(result, sum);
// }void	ft_put_hex(unsigned int num, const char format)
void	ft_put_hex(unsigned int num, int format, int *count)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format, count);
		ft_put_hex(num % 16, format, count);
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

void	ft_print_hex(unsigned int num, const char format, int *count)
{
	if (num == 0)
		ft_putchar('0', count);
	else
		ft_put_hex(num, format, count);
}
