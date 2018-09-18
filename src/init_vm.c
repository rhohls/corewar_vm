/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:35 by ppreez            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/18 10:43:13 by ppreez           ###   ########.fr       */
=======
/*   Updated: 2018/09/18 10:43:18 by rhohls           ###   ########.fr       */
>>>>>>> dfb24afe9f252a0851d85f803d81a348553c64e3
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"



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

static void		size_balance(t_vm *vm, t_list *players, unsigned int size, int count)
{
	t_list			*start;
	u_int			offset;
	int				i;
	int				x;

	offset = (MEM_SIZE - size) / count;
	start = players;
	x = 0;
	while (players)
	{
		i = 0;
		add_cursor_to_vm(vm, x);
		while (i < ((t_player *)(players->content))->program_size)
		{
			vm->core[x] = ((t_player *)(players->content))->program[i];;
			x++;
			i++;
		}
		
		
		x += offset;
		players = players->next;
	}
	
	printf("init cursor at %d\n",x);
	
	print_cursor_info(vm);
	players = start;
}
// also need to load players cursors @ location
// ft_sta
void		load_players(t_vm *vm, char *board, t_list *players)
{
	unsigned int	size;
	int				count;
	t_list 			*start;
	
	size = 0;
	count = 0;
	start = players;
	while (players)
	{
		size += ((t_player *)(players->content))->program_size;
		((t_player *)(players->content))->player_num = ++count;
		players = players->next;
	}
	players = start;
	size_balance(vm, players, size, count);
	
}