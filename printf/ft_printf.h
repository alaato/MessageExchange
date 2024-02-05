/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:46:32 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 20:38:39 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);

void	ft_putnbr(int n, int *count);

void	ft_putadress(unsigned long n, int *count);

void	put_unsigned(int n, int *count);

void	ft_putstr(char *s, int *count);

void	ft_putchar(char c, int *count);

void	ft_print_hex(unsigned int num, const char format, int *count);

int		ft_printf(const char *fmt, ...);

#endif