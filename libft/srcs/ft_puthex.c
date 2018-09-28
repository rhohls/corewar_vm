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

void	ft_puthex(int num)
{
	int	char_print;

	char_print = -10;
	if (num >= 10 && num <= 15)
	{
		char_print += 'a' + num;
		ft_putchar(char_print);
	}
	else if (num >= 16)
	{
		ft_puthex(num / 16);
		ft_puthex(num % 16);
	}
	else if (num < 10)
		ft_putchar(num + '0');
}
