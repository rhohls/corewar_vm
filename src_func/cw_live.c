/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 12:46:28 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_player	*get_player(t_vm *vm, int player_num)
{
	t_player	*player;
	t_list		*node;

	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		if (player->player_num == player_num)
			return (player);
		node = node->next;
	}
	return (NULL);
}

static void	apply_life(t_vm *vm, int player_num)
{
	t_player	*player;

	player = get_player(vm, player_num);
	if (player && player->alive)
	{
		player->nbr_lives++;
		vm->life_info.last_live_playernum = player_num;
		vm->life_info.nbr_live_calls++;
	}
}

int			cw_live(t_vm *vm, t_cursor *cursor)
{
	int player_num;

	cursor->live_call = 1;
	player_num = get_dir(1, vm, cursor, 0);
	apply_life(vm, player_num);
	return (5);
}
