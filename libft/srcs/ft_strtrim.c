/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:14:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/07 11:41:15 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

static char	*ft_strtrim_ret(int begin_w, int end_w, char const *str)
{
	char	*new_str;
	char	*work_str;

	if (!(new_str = ft_strnew(ft_strlen(str) - begin_w - end_w)))
		return (NULL);
	work_str = (char *)(str + begin_w);
	ft_strncpy(new_str, work_str, ft_strlen(str) - begin_w - end_w);
	return (new_str);
}

char		*ft_strtrim(char const *str)
{
	char	*work_str;
	int		begin_w;
	int		end_w;

	if (str == NULL)
		return (NULL);
	begin_w = 0;
	end_w = 0;
	work_str = (char *)str;
	while (ft_whitespace(*work_str))
	{
		begin_w++;
		work_str++;
		if (*work_str == '\0')
			return (ft_strnew(begin_w));
	}
	work_str = (char *)(str + ft_strlen(str) - 1);
	while (ft_whitespace(*work_str))
	{
		end_w++;
		work_str--;
	}
	return (ft_strtrim_ret(begin_w, end_w, str));
}
