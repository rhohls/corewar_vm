/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:46:13 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/11 14:02:33 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		kill_players(t_vm *vm)
{
	t_player	*player;
	t_list		*node;
	
	node = vm->player_list->start;
	while(node)
	{
		player = node->content;
		
		if (player->nbr_lives < NBR_LIVE)
		{
			player->alive = 0;
			vm->nbr_dead++;
		}
	}
}

/*
** Will end the game if all players are dead
*/

int		cycle_checkup(t_vm *vm)
{
	if (vm->life_info.nbr_live_calls >= NBR_LIVE ||
			vm->life_info.nbr_live_reached)
	{
		vm->life_info.nbr_checkups = 0;
		vm->life_info.nbr_live_reached = 1;
		kill_players(vm);
		if (vm->nbr_dead <= (int)vm->player_list->length - 1)
			return (1);
	}
	else if (vm->life_info.nbr_checkups >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->life_info.nbr_checkups = 0;
	}
	vm->curr_cycle = 0;
	vm->life_info.nbr_checkups++;
	return (0);
}