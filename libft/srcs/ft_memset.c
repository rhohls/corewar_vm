/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:56:38 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/30 12:04:33 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

void	*ft_memset(void *a, int c, size_t len)
{
	char *b;

	b = (char *)a;
	while (len > 0)
	{
		*b = (unsigned char)c;
		len--;
		b++;
	}
	return (a);
}
