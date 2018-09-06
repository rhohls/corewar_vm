/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextdig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:51:35 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/18 12:36:37 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nextdig(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	return (i);
}
