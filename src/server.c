/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:08:39 by aatarban          #+#    #+#             */
/*   Updated: 2024/02/05 18:59:49 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

struct s_binary_character	g_to_print;

int	bin_to_char(char *binary)
{
	int	i;
	int	sum;

	i = 8;
	sum = 0;
	while (--i >= 0)
	{
		if (binary[i] == '1')
		{
			sum += 1 << (7 - i);
		}
	}
	return (sum);
}

void	sig_usr_handler(int sig)
{
	char	character;

	(void)sig;
	if (g_to_print.len > 0)
	{
		if (sig == SIGUSR1)
			g_to_print.binary[g_to_print.len] = '0';
		else
			g_to_print.binary[g_to_print.len] = '1';
		g_to_print.len--;
	}
	else
	{
		character = bin_to_char(g_to_print.binary);
		while (++g_to_print.len < 8)
			g_to_print.binary[g_to_print.len] = 0;
		g_to_print.len = 7;
		g_to_print.binary[g_to_print.len] = 0;
		write(1, &character, 1);
	}
}

int	main(void)
{
	struct sigaction	sa_usr;
	pid_t				pid;

	g_to_print.len = 7;
	pid = getpid();
	sa_usr.sa_handler = sig_usr_handler;
	sa_usr.sa_flags = 0;
	sigemptyset(&sa_usr.sa_mask);
	ft_printf(" %s [PID] : %d %s hi\n", BLU, pid, WHT);
	sigaction(SIGUSR1, &sa_usr, NULL);
	sigaction(SIGUSR2, &sa_usr, NULL);
	while (1)
		pause();
}
