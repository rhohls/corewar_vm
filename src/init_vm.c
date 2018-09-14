/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:35 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/14 09:51:40 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void init_vm(t_vm *vm)
{
	set_op_tab(vm);// whyyyyyy!??!
	vm->file_lines = NULL;
	vm->cursor_stack = ft_stacknew();
	vm->curr_cycle = 0;
	vm->nbr_dead = 0;
	vm->player_list = ft_stacknew();
	vm->cycle_death = CYCLE_TO_DIE;
}

static void		size_balance(char *board, t_list *players, unsigned int size)
{
	t_list			*start;
	u_int			offset;
	int				i;
	int				x;

	offset = (MEM_SIZE - size) / MAX_PLAYERS;
	start = players;
	x = 0;
	while (players)
	{
		i = 0;
		while (((t_player *)(players->content))->program[i])
		{
			board[x] = ((t_player *)(players->content))->program[i];
			x++;
			i++;
		}
		x += offset;
		players = players->next;
	}
	players = start;
}
// also need to load players cursors @ location
// ft_sta
void		load_players(t_vm *vm, char *board, t_list *players)
{
	unsigned int	size;
	t_list 			*start;
	
	size = 0;
	start = players;
	while (players)
	{
		size += ((t_player *)(players->content))->program_size;
		players = players->next;
	}
	players = start;
	size_balance(board, players, size);
	
}