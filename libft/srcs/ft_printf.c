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

static void	do_print(va_list var_list, char *input, int ind)
{
	char		*str;
	char		c;
	int			num;

	if (input[ind] == 's')
	{
		str = va_arg(var_list, char *);
		ft_putstr(str);
	}
	else if (input[ind] == 'i' || input[ind] == 'd')
	{
		num = va_arg(var_list, int);
		ft_putnbr(num);
	}
	else if (input[ind] == 'x')
	{
		num = va_arg(var_list, int);
		ft_puthex(num);
	}
	else if (input[ind] == 'c')
	{
		c = va_arg(var_list, int);
		ft_putchar(c);
	}
}

int			ft_printf(char *input, ...)
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
				do_print(var_list, input, ind);
			else
			{
				ind--;
				ft_putchar('%');
			}
		}
		else
			ft_putchar(input[ind]);
		ind++;
	}
	va_end(var_list);
	return (1);
}
