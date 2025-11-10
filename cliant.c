/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:10:32 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/10 21:44:36 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	restart(int	signal)
{
	(void)signal;
}

void	char_bit(char *str, pid_t pid)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if (*str >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			pause();
		}
		str++;
	}
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	struct sigaction	sc;

	if (argc != 3)
		return (0);
	sc.sa_handler = restart;
	sigemptyset(&sc.sa_mask);
	sigaction(SIGUSR1, &sc, NULL);
	pid = (pid_t)ft_atoi(argv[1]);
	str = argv[2];
	char_bit(str, pid);
}

