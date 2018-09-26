/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:08:27 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/21 09:42:45 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdarg.h>
#include <stdlib.h>

static void	do_print(va_list var_list, char *input, int ind, int fd)
{
	char		*str;
	char		c;
	int			num;

	if (input[ind] == 's')
	{
		str = va_arg(var_list, char *);
		ft_putstr_fd(str, fd);
	}
	else if (input[ind] == 'i' || input[ind] == 'd')
	{
		num = va_arg(var_list, int);
		ft_putnbr_fd(num, fd);
	}
	else if (input[ind] == 'x')
	{
		num = va_arg(var_list, int);
		ft_puthex_fd(num, fd);
	}
	else if (input[ind] == 'c')
	{
		c = va_arg(var_list, int);
		ft_putchar_fd(c, fd);
	}
}

int			ft_dprintf(int fd, char *input, ...)
{
	va_list	var_list;
	int		ind;

	ind = 0;
	va_start(var_list, input);
	while (input[ind])
	{
		if (input[ind] == '%')
		{
			ind++;
			if (input[ind] == 's' || input[ind] == 'i' || input[ind] == 'x'
			|| input[ind] == 'd' || input[ind] == 'c')
				do_print(var_list, input, ind, fd);
			else
			{
				ind--;
				ft_putchar_fd('%', fd);
			}
		}
		else
			ft_putchar_fd(input[ind], fd);
		ind++;
	}
	va_end(var_list);
	return (1);
}
