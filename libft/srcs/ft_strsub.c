/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:11:43 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 14:12:29 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char *str_new;

	if (str == NULL)
		return (NULL);
	if (!(str_new = ft_strnew(len)))
		return (NULL);
	ft_strncpy(str_new, (str + start), len);
	return (str_new);
}
