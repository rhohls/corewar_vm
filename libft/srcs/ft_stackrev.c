/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:35:53 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:12:18 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void		ft_stackrev(t_stack *stack)
{
	t_stack	*new;
	t_list	*node;
	int		i;

	i = stack->length;
	if (!stack || !(stack->start))
		return ;
	new = ft_stacknew();
	node = stack->start;
	while (i > 0 && node)
	{
		node = ft_stackpop(stack);
		ft_stackpush(new, node);
		i--;
	}
	stack->start = new->start;
	stack->length = new->length;
	free(new);
}
