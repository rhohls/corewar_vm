/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:09:40 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 08:56:10 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static size_t	word_count(char const *s, char c)
{
	char const	*tmp;
	size_t		count;

	count = 0;
	tmp = s;
	while (*tmp != '\0')
	{
		while (*tmp == c && *tmp != '\0')
			tmp++;
		while (*tmp != c && *tmp != '\0')
			tmp++;
		if (*(tmp - 1) != c)
			count++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	char const	*tmp;
	size_t		count;

	tmp = s;
	count = 0;
	while (*tmp != c && *tmp != '\0')
	{
		tmp++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		j;
	char const	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = s;
	if ((ret = (char **)malloc(sizeof(char *) * word_count(s, c) + 1)) != NULL)
	{
		i = 0;
		while (i < word_count(s, c))
		{
			while (*tmp == c && *tmp != '\0')
				tmp++;
			ret[i] = (char *)malloc(sizeof(char) * word_len(tmp, c) + 1);
			j = 0;
			while (*tmp != c && *tmp != '\0')
				ret[i][j++] = *tmp++;
			ret[i++][j] = '\0';
		}
		ret[i] = NULL;
	}
	return (ret);
}
