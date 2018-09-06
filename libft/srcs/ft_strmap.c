/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:49:58 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:34:02 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	char	*newstr;

	if (!str)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = f(str[i]);
		i++;
	}
	return (newstr);
}
