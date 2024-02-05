/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:42 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/09 21:05:12 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putendl(char *s)
{
	int	size;

	size = ft_strlen(s);
	write(1, s, size);
	write(1, "\n", 1);
}
