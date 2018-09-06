/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:20:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/11 09:35:20 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	chck;

	chck = 0;
	while (*dest)
	{
		chck++;
		dest++;
	}
	if (chck >= len)
		return (len + ft_strlen(src));
	ft_strncat(dest, src, len - chck - 1);
	return (chck + ft_strlen(src));
}
