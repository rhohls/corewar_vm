/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:58:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 14:55:38 by rhohls           ###   ########.fr       */
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

static int	atoi_return(int neg, int i, int ret, int num_dig)
{
	if (neg)
		ret *= (-1);
	if (i - num_dig > 18)
	{
		if (neg)
			return (0);
		else
			return (-1);
	}
	return (ret);
}

int			ft_atoi(const char *str)
{
	int ret;
	int i;
	int neg;
	int num_dig;

	ret = 0;
	neg = 0;
	i = atoi_space(str, &neg);
	num_dig = i;
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > '9'))
			break ;
		ret *= 10;
		ret += str[i] - 48;
		i++;
	}
	return (atoi_return(neg, i, ret, num_dig));
}
