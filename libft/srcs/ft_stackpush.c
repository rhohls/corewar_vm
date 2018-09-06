/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:50:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/12 13:50:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_stackpush(t_stack *stack, t_list *new_node)
{
	if (stack && new_node)
	{
		new_node->next = stack->start;
		stack->start = new_node;
		stack->length++;
	}
}
