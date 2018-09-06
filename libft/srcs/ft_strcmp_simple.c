/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:37:15 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:41:35 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp_simple(const char *s1, const char *s2)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1)
	{
		if (*str2 == '\0')
			return (0);
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
