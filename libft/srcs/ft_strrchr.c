/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:22:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/25 08:33:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*string;
	int		cnt;

	string = (char *)str;
	cnt = (int)ft_strlen(string);
	string += cnt;
	while (cnt > 0)
	{
		if (*string == (char)c)
			return (string);
		string--;
		cnt--;
	}
	if (*string == (char)c)
		return (string);
	return (NULL);
}
