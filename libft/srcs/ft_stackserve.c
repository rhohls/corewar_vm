/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackserve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:46:00 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:52:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_stackserve(t_stack *stack)
{
	t_list *node;
	t_list *previous;

	previous = NULL;
	if (stack && stack->start)
	{
		node = stack->start;
		while (node->next)
		{
			previous = node;
			node = node->next;
		}
		if (previous)
			previous->next = NULL;
		stack->length--;
		if (stack->length == 0)
			stack->start = NULL;
	}
	else
		return (NULL);
	return (node);
}
