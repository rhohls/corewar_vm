/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:14:08 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 16:14:19 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	putnbr_hex(int octet, int rem, int fd)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		putnbr_hex(octet >> 4, rem - 1, fd);
	write(fd, base + (octet % 16), 1);
}

void	mem_putchar(unsigned char const *ptr, int fd)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(fd, ptr, 1);
	else
		write(fd, ".", 1);
}

int		check_line(unsigned char const *addr)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < 16)
	{
		ret += addr[i];
		i++;
	}
	return (ret == 0 ? 1 : 0);
}

/*
** tab[0] = ind
** tab[1] = a
** tab[2] = stop
** tab[3] = location
*/

void	print_board_location(unsigned char const *core, size_t size, int fd)
{
	size_t tab[4];

	tab[2] = 64;
	tab[0] = 0;
	while (tab[0] < size)
	{
		tab[1] = 0;
		tab[3] = tab[0] + 1;
		write(fd, "0x", 2);
		while (tab[3] < 4096)
		{
			write(fd, "0", 1);
			tab[3] *= 16;
		}
		ft_puthex_fd(tab[0], fd);
		write(fd, ": ", 3);
		while (tab[1] < tab[2] && tab[1] + tab[0] < size)
		{
			putnbr_hex(*(core + tab[0] + tab[1]), 2, fd);
			write(fd, " ", 1);
			tab[1]++;
		}
		write(fd, "\n", 1);
		tab[0] += tab[2];
	}
}
