/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:43:09 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 08:35:34 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	int num_dig;

	num_dig = ft_int_len(num);
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= (-1);
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}
