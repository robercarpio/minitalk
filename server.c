/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rober <rober@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:06:12 by rober             #+#    #+#             */
/*   Updated: 2024/12/26 18:13:01 by rober            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits_received = 0;

	(void)context;
	if (sig == SIGUSR1)
		c = (c << 1);
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bits_received++;
	if (bits_received == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bits_received = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID Server: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
