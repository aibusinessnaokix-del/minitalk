/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:58:50 by naoki             #+#    #+#             */
/*   Updated: 2025/11/10 21:32:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_char(int signal, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	pid_t					cliant_pid;

	(void)context;
	cliant_pid = info->si_pid;
	if (signal == SIGUSR2)
		c = c | 1 << i;
	if (i == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		i++;
	kill(cliant_pid, SIGUSR1);
}



int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = bit_char;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("pid: %d\n", pid);
	while(true)
		pause();
}
