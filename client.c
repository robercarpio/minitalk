/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:13:50 by rober             #+#    #+#             */
/*   Updated: 2024/12/26 18:17:02 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_aux.h"

volatile sig_atomic_t	g_got_signal = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_got_signal = 1;
	}
}

void	send_signal(pid_t server_pid, int signal)
{
	if (kill(server_pid, signal) == -1)
	{
		exit(EXIT_FAILURE);
	}
}

void	send_bit(pid_t server_pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
			send_signal(server_pid, SIGUSR2);
		else
			send_signal(server_pid, SIGUSR1);
		usleep(100);
		while (!g_got_signal)
			pause();
		g_got_signal = 0;
	}
}

void	send_string(pid_t server_pid, const char *str)
{
	while (*str)
	{
		send_bit(server_pid, *str);
		str++;
	}
	send_bit(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(2, "Uso: ./client <PID> <mensaje>\n", 30);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		write(2, "PID inválido\n", 14);
		return (EXIT_FAILURE);
	}
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_string(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
