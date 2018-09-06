/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:36:48 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:37:54 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str_new;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(str_new = ft_strnew((size_t)(ft_strlen((char *)s1)
					+ ft_strlen((char *)s2) + 1))))
		return (NULL);
	ft_strcpy(str_new, (char *)s1);
	ft_strcpy((str_new + ft_strlen((char *)s1)), (char *)s2);
	return (str_new);
}
