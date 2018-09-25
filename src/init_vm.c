/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:35 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/18 13:38:13 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void init_vm(t_vm *vm)
{
	ft_bzero(vm, sizeof(t_vm));
	set_op_tab(vm);//  (its for the no. cycles)
	vm->cursor_stack = ft_stacknew();
	// vm->file_lines = NULL;
	// vm->curr_cycle = 0;
	// vm->nbr_dead = 0;
	
	vm->player_list = ft_stacknew();
	vm->cycle_to_die = CYCLE_TO_DIE;
}

/*
** offset[0] = size of offset between player starts
** offset[1] = index of player start
** 
** Nested while loads players onto board
*/

static void		insert_player(t_vm *vm, int player_start, t_player *player)
{
	int i;
	
	i = 0;
	while (i < player->program_size)
	{
		vm->core[i + player_start] = player->program[i];
		i++;
	}
	add_initial_player_cursor(vm, player_start, player);
	player->start_location = player_start;	
}

static void		size_balance(t_vm *vm, unsigned int size)
{
	t_list			*player_node;
	int				offset;
	int				start_location;
	t_player		*player;

	offset = MEM_SIZE / vm->player_list->length;
	start_location = 0;
	player_node = vm->player_list->start;
	while (player_node)
	{
		player = player_node->content;
		insert_player(vm, start_location, player);
		start_location += offset;		
		player_node = player_node->next;
	}
}

void		load_players(t_vm *vm, char *board, t_list *player)
{
	unsigned int	size;
	t_list 			*start;
	
	size = 0;
	start = player;
	while (player)
	{
		size += ((t_player *)(player->content))->program_size;
		name_replacer(vm, player);
		player = player->next;
	}
	player = start;
	size_balance(vm, size);
}