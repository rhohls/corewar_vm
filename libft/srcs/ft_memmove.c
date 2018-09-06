/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:37:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/22 09:42:01 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *ret;
	char *srcstart;
	char *dststart;

	srcstart = (char*)src;
	dststart = (char*)dst;
	ret = (char *)dst;
	if (len == 0 || dst == src)
		return (dst);
	if (src < dst)
	{
		dststart += len - 1;
		srcstart += len - 1;
		while (len--)
			*dststart-- = *srcstart--;
	}
	else
	{
		while (len--)
			*dststart++ = *srcstart++;
	}
	return (dst);
}
