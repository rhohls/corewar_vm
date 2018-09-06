/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:20:23 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:28:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst)
	{
		if ((*alst)->next != NULL)
			ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}

void	ft_del_onlylist(t_list **alst)
{
	if (alst && *alst)
	{
		if ((*alst)->next != NULL)
			ft_del_onlylist(&((*alst)->next));
		ft_memdel((void **)alst);
	}
}
