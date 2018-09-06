/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:11:10 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/30 07:58:41 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	char	*str_char;
	int		num_char;

	num_char = 0;
	str_char = (char *)str;
	while (*str_char++)
		num_char++;
	return (num_char);
}
