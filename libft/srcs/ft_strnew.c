/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:06:39 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 14:39:25 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "string.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
