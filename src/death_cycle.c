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

void	kill_players(t_vm *vm)
{
	t_player	*player;
	t_list		*node;

	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		if (player->nbr_lives < 1)
		{
			player->alive = 0;
			vm->nbr_dead++;
		}
		player->nbr_lives = 0;
		node = node->next;
	}
}

void	remove_cursor_from_list(t_cursor *cursor, t_vm *vm)
{
	t_list		*curr_node;
	t_list		*prev_node;

	prev_node = NULL;
	curr_node = vm->cursor_stack->start;
	while (curr_node)
	{
		if (curr_node->content == cursor)
		{
			if (prev_node)
				prev_node->next = curr_node->next;
			else
				vm->cursor_stack->start = curr_node->next;
			free(curr_node->content);
			free(curr_node);
			return ;
		}
		prev_node = curr_node;
		curr_node = curr_node->next;
	}
}

void	kill_cursors(t_vm *vm)
{
	t_list		*cursor_node;
	t_cursor	*cursor;

	cursor_node = vm->cursor_stack->start;
	while (cursor_node)
	{
		cursor = cursor_node->content;
		cursor_node = cursor_node->next;
		if (cursor->live_call < 1)
			remove_cursor_from_list(cursor, vm);
		else
			cursor->live_call = 0;
	}
}

/*
** Will end the game if all players are dead
**
** every cycle to death check everyone is alive
** kill players as needed
** only decrease cycle to die if nbr lives is reached or max check
**
** also kill cursors
*/

int		cycle_checkup(t_vm *vm)
{
	vm->life_info.nbr_checkups++;
	if (vm->life_info.nbr_live_calls >= NBR_LIVE ||
			vm->life_info.nbr_checkups >= MAX_CHECKS)
	{
		vm->life_info.nbr_live_calls = 0;
		vm->life_info.nbr_checkups = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
		kill_players(vm);
		kill_cursors(vm);
	}
	vm->curr_cycle = 0;
	if (vm->cycle_to_die <= 0)
		return (1);
	else
		return (0);
}
