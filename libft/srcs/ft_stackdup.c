/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:35:53 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:28:22 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstdup(t_list *node)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = ft_memalloc(sizeof(node->content_size))))
	{
		free(new);
		return (NULL);
	}
	ft_memmove(new->content, node->content, node->content_size);
	new->content_size = node->content_size;
	new->next = NULL;
	return (new);
}

t_stack		*ft_stackdup(t_stack *stack)
{
	t_stack *new;
	t_list	*node;
	t_list	*node_new;

	new = ft_stacknew();
	node = stack->start;
	while (node)
	{
		node_new = ft_lstdup(node);
		ft_stackqueue(new, node_new);
		node = node->next;
	}
	return (new);
}
