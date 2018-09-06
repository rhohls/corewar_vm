/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:28:38 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 14:34:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strstr(const char *stringbig, const char *stringsmall)
{
	char *haystack;
	char *needle;
	char *hay_ret;

	haystack = (char *)stringbig;
	hay_ret = haystack;
	needle = (char *)stringsmall;
	if (!ft_strlen((char *)stringsmall))
		return ((char *)stringbig);
	else if (!ft_strlen((char *)stringbig))
		return (NULL);
	while (*haystack)
	{
		if (ft_strcmp_simple(haystack, needle) == 0)
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
