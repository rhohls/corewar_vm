/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:50:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:49:34 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_stackpop(t_stack *stack)
{
	t_list *popped;

	if (stack && stack->start)
	{
		popped = stack->start;
		stack->start = stack->start->next;
		stack->length--;
		popped->next = NULL;
	}
	else
		popped = NULL;
	return (popped);
}
