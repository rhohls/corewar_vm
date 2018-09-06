/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:44:44 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 10:22:37 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*str1 && n)
	{
		if ((*str1 != *str2) || (!(*str2)))
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	if (n > 0)
		return (*str1 - *str2);
	str1--;
	str2--;
	if (*str2 == '\0' && n == 0)
		return (0);
	return (*--str1 - *--str2);
}
