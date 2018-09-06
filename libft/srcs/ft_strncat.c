/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:34:56 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/25 08:23:34 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	char *strnew;

	strnew = str1;
	while (*strnew)
		strnew++;
	while (*str2 && n > 0)
	{
		*strnew = *str2;
		strnew++;
		str2++;
		n--;
	}
	*strnew = '\0';
	return (str1);
}
