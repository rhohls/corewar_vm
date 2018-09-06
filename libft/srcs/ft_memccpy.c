/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:16:06 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 11:04:23 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dest;
	unsigned char	*sourc;

	dest = (unsigned char*)dst;
	sourc = (unsigned char*)src;
	ch = (unsigned char)c;
	while (n > 0)
	{
		*dest = *sourc;
		if (*sourc == ch)
		{
			dest++;
			return (dest);
		}
		n--;
		dest++;
		sourc++;
	}
	return (NULL);
}
