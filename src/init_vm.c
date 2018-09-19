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

void replace_live(t_vm *vm, t_list *players); // TO BE MOVED TO HEADER

void init_vm(t_vm *vm)
{
	// set_makop_tab(vm);// whyyyyyy!??!
	vm->file_lines = NULL;
	vm->cursor_stack = ft_stacknew();
	vm->curr_cycle = 0;
	vm->nbr_dead = 0;
	vm->player_list = ft_stacknew();
	vm->cycle_death = CYCLE_TO_DIE;
}

/*
** offset[0] = size of offset between player starts
** offset[1] = index of player start
*/

static void		size_balance(t_vm *vm, t_list *players, unsigned int size, int count)
{
	t_list			*start;
	u_int			offset[2];
	int				i;
	int				x;

	offset[0] = MEM_SIZE / count;
	offset[1] = 0;
	start = players;
	x = 0;
	while (players)
	{
		i = 0;
		add_cursor_to_vm(vm, x);
		x = offset[1];
		while (i < ((t_player *)(players->content))->program_size)
		{
			vm->core[x] = ((t_player *)(players->content))->program[i];
			x++;
			i++;
		}	
		offset[1] += offset[0];
		players = players->next;
	}
	players = start;
	printf("init cursor at %d\n", x);
	// print_cursor_info(vm);
}
// also need to load players cursors @ location
// ft_sta
void		load_players(t_vm *vm, char *board, t_list *player)
{
	unsigned int	size;
	int				count;
	t_list 			*start;
	
	size = 0;
	count = 0;
	start = player;
	while (player)
	{
		size += ((t_player *)(player->content))->program_size;
		((t_player *)(player->content))->player_num = ++count;
		name_replacer(vm, player);
		player = player->next;
	}
	player = start;
	size_balance(vm, player, size, count);
	
}