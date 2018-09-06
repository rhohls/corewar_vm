/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:28:10 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/25 08:23:54 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *str1, const char *str2)
{
	char *strnew;

	strnew = str1;
	while (*strnew)
		strnew++;
	while (*str2)
	{
		*strnew = *str2;
		strnew++;
		str2++;
	}
	*strnew = *str2;
	return (str1);
}
