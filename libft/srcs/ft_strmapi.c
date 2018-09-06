/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:49:58 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:34:18 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (!str)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = f(i, str[i]);
		i++;
	}
	return (newstr);
}
