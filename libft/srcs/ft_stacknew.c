/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:52:26 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 08:55:03 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_stack	*ft_stacknew(void)
{
	t_stack *ret;

	if (!(ret = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	ret->start = NULL;
	ret->length = 0;
	return (ret);
}
