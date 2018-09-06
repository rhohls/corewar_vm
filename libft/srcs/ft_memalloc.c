/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:35:45 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/25 07:51:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_pt;

	if (size == 0)
		return (NULL);
	if (!(new_pt = malloc(size)))
		return (NULL);
	ft_memset(new_pt, 0, size);
	return (new_pt);
}
