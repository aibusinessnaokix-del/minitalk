/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naoki <naoki@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-09 12:58:50 by naoki             #+#    #+#             */
/*   Updated: 2025-11-09 12:58:50 by naoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	char_bit(char c)
{
	int	i;
	int	count;
	
	i = 8;
	count = 0;
	while (i-- > 0)
	{
	if (c >> i & 1)
		count = count * 2 + 1;
	else
		count = count * 2;
	}
	return (count);
}

void	bit_char(void)
{
	char	c;

	c = 0;
	c = c | 1 << 6;
	c = c | 1 << 3;
	write (1, &c, 1);
	write (1, "\n", 1);
}

//int	main(int argc, char **argv, char **emvp)
//{
//	int	i;
	
//	i = 0;
//	while (emvp[i])
//		printf("%s\n", emvp[i++]);
//}