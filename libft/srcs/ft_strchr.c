/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:53:28 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/25 08:28:26 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char *string;

	string = (char *)str;
	while (*string)
	{
		if (*string == (char)c)
			return (string);
		string++;
	}
	if (*string == (char)c)
		return (string);
	return (NULL);
}
