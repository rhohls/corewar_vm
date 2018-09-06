/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:25:35 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/21 14:01:54 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static int	atoi_space(const char *str, int *neg)
{
	int i;

	i = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		*neg = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (i);
}

static int	atoi_return(int neg, int long ret)
{
	if (neg)
		ret *= (-1);
	if ((ret < INTMIN) || (ret > INTMAX))
		return (0);
	return (ret);
}

int			ft_atoi_long(const char *str)
{
	int long	ret;
	int			i;
	int			neg;
	int			num_dig;

	ret = 0;
	neg = 0;
	i = atoi_space(str, &neg);
	num_dig = i;
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		ret *= 10;
		ret += str[i] - 48;
		i++;
	}
	return (atoi_return(neg, ret));
}
