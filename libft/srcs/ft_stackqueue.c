/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:05:06 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:46:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_stackqueue(t_stack *stack, t_list *new_node)
{
	t_list *temp;

	if (stack && new_node)
	{
		if (!(stack->start) || stack->length == 0)
			stack->start = new_node;
		else
		{
			temp = stack->start;
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
		}
		new_node->next = NULL;
		stack->length++;
	}
}
