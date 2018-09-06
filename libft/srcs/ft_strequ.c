/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:44:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:39:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

int	ft_strequ(char const *str1, char const *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strcmp(str1, str2) == 0)
		return (1);
	else
		return (0);
}
