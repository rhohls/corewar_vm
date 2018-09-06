/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:35:53 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:28:17 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void		ft_stackdel(t_stack **stack, void (*del)(void*, size_t))
{
	if (stack && *stack)
	{
		ft_lstdel(&((*stack)->start), del);
		free(*stack);
		*stack = NULL;
	}
}

void		ft_del_onlystack(t_stack **stack)
{
	if (stack && *stack)
	{
		ft_del_onlylist(&((*stack)->start));
		free(*stack);
		*stack = NULL;
	}
}
