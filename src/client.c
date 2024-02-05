/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:09:27 by aatarban          #+#    #+#             */
/*   Updated: 2024/02/05 17:46:27 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	send_bin_to_server(char c, int pid)
{
	int	bits[8];
	int	i;
	int	is_sent;

	i = -1;
	while (++i < 8)
	{
		bits[i] = (c & (1 << i)) != 0;
		if (bits[i] == 0)
			is_sent = kill(pid, SIGUSR1);
		else
			is_sent = kill(pid, SIGUSR2);
		usleep(200);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	if (argc < 3)
	{
		write(1, "unsufficient arguments\n", 24);
		return (1);
	}
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_bin_to_server(argv[2][i], pid);
		i++;
	}
	send_bin_to_server(10, pid);
	return (0);
}
