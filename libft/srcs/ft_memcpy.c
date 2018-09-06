/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:40:15 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 11:01:44 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dest;
	char *sourc;

	sourc = (char *)src;
	dest = (char *)dst;
	while (n > 0)
	{
		*dest++ = *sourc++;
		n--;
	}
	return (dst);
}
