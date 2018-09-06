/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:55:39 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:28:12 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *newlst)
{
	if (alst && newlst)
	{
		newlst->next = *alst;
		*alst = newlst;
	}
}

void	ft_lstaddfront(t_list **alst, t_list *new_lst)
{
	t_list *node;

	if (!alst || !new_lst)
		return ;
	if (*alst == NULL)
	{
		*alst = new_lst;
		return ;
	}
	node = *alst;
	while (node->next != NULL)
		node = node->next;
	node->next = new_lst;
}
