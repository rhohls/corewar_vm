/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:01:51 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 08:35:03 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int num)
{
	int num_dig;

	num_dig = ft_int_len(num);
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= (-1);
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}
