/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:44:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:13:07 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strnequ(char const *str1, char const *str2, size_t n)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strncmp(str1, str2, n) == 0)
		return (1);
	else
		return (0);
}
