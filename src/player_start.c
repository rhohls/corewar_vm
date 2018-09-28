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

/*
**	Sorry for the terrible function name following this comment.
**	This function uses a cursors owner number to find
** 	the appropriate colour index to print in ncurses
*/

#include <unistd.h>

int		get_colour_ref(t_vm *vm, int byte_index)
{
	return (vm->cwv.colour_ref[byte_index]);
}

void	player(t_vm *vm)
{
	t_player	*player;
	t_list		*player_node;
	U_INT		start;

	player_node = vm->player_list->start;
	start = 1;
	while (player_node)
	{
		player = (t_player *)(player_node->content);
		if (player->start_loc < 0)
			player->start_loc = start++;
		player_node = player_node->next;
	}
}

void	set_player_start(t_vm *vm)
{
	player(vm);
}
