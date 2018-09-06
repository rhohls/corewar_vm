/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:58:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 08:59:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

int		check_line(unsigned char const *addr)
{
	int ret;
	int	line_val;
	int i;
	
	i = 0;
	ret = 0;
	
	while (i < 16)
	{
		ret += addr[i];
		i++;
	}
	return(ret == 0 ? 1 : 0);		
}

void	print_memory(const void *addr, size_t size, int printable, int location)
{
	size_t	ind;
	size_t	a;
	int		skip;
	int		skip_prev;
	unsigned char const *ptr = addr;

	ind = 0;
	skip_prev = 0;
	while (ind < size)
	{
		skip = check_line(&(ptr[ind]));
		if (skip && !skip_prev)
		{
			skip_prev = 1;
			write(1, "*\n", 2);
		}
		else if (!skip)
		{
			skip_prev = 0;
			if (location)
			{
				ft_putnbr_hex(ind,7);
				write(1, " ", 1);
			}
			a = 0;
			while (a < 16 && a + ind < size)
			{
				ft_putnbr_hex(*(ptr + ind + a), 2);
				write(1, " ", 1);
				a++;
			}
			while (a < 16)
			{
				write(1, "  ", 2);
				if (a % 2)
					write(1, " ", 1);
				a++;
			}
			if (printable)
			{
				a = 0;
				while (a < 16 && a + ind < size)
				{
					sp_putchar(ptr + a + ind);
					a++;
				}
			}
			write(1, "\n", 1);
		}
		ind += 16;
	}
}