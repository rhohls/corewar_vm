/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:35:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 08:45:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*curr;

	if (lst && f)
	{
		new = f(lst);
		curr = new;
		lst = lst->next;
		while (lst)
		{
			curr->next = f(lst);
			curr = curr->next;
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
