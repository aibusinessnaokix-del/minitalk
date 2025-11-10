/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:34:15 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/10 21:33:06 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "./libft/ft_printf.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <bits/sigaction.h>

/*server.c*/
void	bit_char(int signal, siginfo_t *info, void *context);


#endif