/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:27:52 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/20 10:28:41 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void    player(t_vm *vm)
{
    t_player    *player;
    t_list      *player_node;
	u_int		start;
    
    player_node = vm->player_list->start;
	start = 1;
    while (player_node)
    {
        player = (t_player *)(player_node->content);
		if (player->start_location < 0)
			player->start_location = start++;
        player_node = player_node->next;
    }
}

void	set_player_start(t_vm *vm)
{
	player(vm);
}