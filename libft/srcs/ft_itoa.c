/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:57:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 10:23:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

static int	ft_int_len_itoa(int num)
{
	int				num_dig;

	num_dig = 0;
	if (num < 0)
		num_dig++;
	while (num)
	{
		num /= 10;
		num_dig++;
	}
	return (num_dig);
}

static char	*ft_itoa_str(int num, char *str, unsigned int pos)
{
	unsigned int	nb;

	pos--;
	if (num < 0)
	{
		nb = -num;
		str[0] = '-';
	}
	else
		nb = num;
	if (nb >= 10)
	{
		ft_itoa_str((nb / 10), str, pos);
		str[pos] = ((nb % 10) + '0');
	}
	else
		str[pos] = (nb + '0');
	return (str);
}

char		*ft_itoa(int num)
{
	char			*str_new;
	int				num_dig;

	num_dig = ft_int_len_itoa(num);
	if (!(str_new = ft_strnew(num_dig)))
		return (NULL);
	if (num == 0)
	{
		str_new = ft_strnew(1);
		str_new[0] = '0';
		return (str_new);
	}
	str_new = ft_itoa_str(num, str_new, num_dig);
	return (str_new);
}
