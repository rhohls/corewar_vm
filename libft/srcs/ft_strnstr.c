/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:37:20 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/07 11:40:22 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *stringbig, const char *stringsmall, size_t len)
{
	char *haystack;
	char *needle;
	char *hay_ret;

	haystack = (char *)stringbig;
	hay_ret = haystack;
	needle = (char *)stringsmall;
	if ((!ft_strlen(stringbig)) ||
			(ft_strlen(stringsmall) > len))
		return (NULL);
	else if (ft_strncmp(stringbig, stringsmall, len) == 0)
		return ((char *)stringbig);
	else if (!ft_strlen((char *)stringsmall))
		return ((char *)stringbig);
	while (*haystack && (len >= ft_strlen(stringsmall)))
	{
		if (ft_strncmp_simple(haystack, needle, len) == 0)
			return (haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
