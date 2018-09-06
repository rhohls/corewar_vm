/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:44:40 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 14:02:19 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
