/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:39:57 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/26 14:42:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_puthex_fd(int num, int fd)
{
	int	char_print;

	char_print = -10;
	if (num >= 10 && num <= 15)
	{
		char_print += 'a' + num;
		ft_putchar_fd(char_print, fd);
	}
	else if (num >= 16)
	{
		ft_puthex_fd(num / 16, fd);
		ft_puthex_fd(num % 16, fd);
	}
	else if (num < 10)
		ft_putchar_fd(num + '0', fd);
}
