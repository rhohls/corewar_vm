/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:03:59 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/24 14:33:44 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../includes/libft.h"

void	*ft_memchr(const void *s, int i, size_t n)
{
	unsigned char	*str;
	size_t			cnt;

	cnt = 0;
	str = (unsigned char*)s;
	while (cnt < n)
	{
		if (*str == (unsigned char)i)
			return (str);
		cnt++;
		str++;
	}
	return (NULL);
}
