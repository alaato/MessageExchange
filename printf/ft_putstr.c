/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:31:10 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 20:50:41 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		while (s[++i])
		{
			write(1, &s[i], 1);
			*count += 1;
		}
	}
}
