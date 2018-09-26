/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:30:54 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 11:21:20 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	display_winner(t_vm *vm)
{
	t_player	*player;
	
	// printf("%d\n", vm->life_info.last_live_playernum);
	player = get_player(vm, vm->life_info.last_live_playernum);
	if (player)
	{
		if (vm->cwv.mode)
			n_display_winner(vm, player);
		else
			ft_printf("The winner is ...\n\tPlayer %d with name \"%s\"\n", player->player_num, player->name);
	}
	else
	{
		if (vm->cwv.mode)
			n_display_winner(vm, player);
		else
			ft_printf("No one called any live comands\n");
	}
	// t_player	*player;
	// t_list		*node;
	
	// node = vm->player_list->start;
	// while(node)
	// {
	// 	player = node->content;
	// 	if (player->alive == 1)
	// 	{
	// 		ft_// printf("The winer is ...\n\tPlayer \"%s\" number: %d\n", player->name,
	// 					player->player_num);
	// 		break ;
	// 	}
	// 	node = node->next;
	// }	
}

void	cycle_dump(t_vm *vm)
{
	char *line;
	
	if (vm->flags.verbose)
		print_game_state(vm);
	else
		print_board((const unsigned char *)(&(vm->core[0])), MEM_SIZE);
	if (vm->flags.contin)
	{
		ft_putendl("Please enter the next cycle to dump at, or 0 to continue to game end");
		get_next_line(0, &line);
		vm->flags.dump = ft_atoi_long(line);
	}
	else
		exit(0);
}

void	vm_loop(t_vm *vm)
{
	int i = 0;
	int print_update;

	// print_game_state(vm);
	//log init time
	while(1)
	{
		//log new time
		//if new time - init time > frame delay :: then do everything and init time = new time
		if (vm->cwv.mode)
		{
			n_key_get(vm);
			n_print_game_state(vm);
		}
		print_update = 0;
		// printf("Total cycles: %ld Curr cycles: %d\n", vm->total_cycle, vm->curr_cycle);
		incr_all_cursor(vm, &print_update);
		vm->curr_cycle++;
		vm->total_cycle++;
		
		// curr_cycle gets set to 0 during checkup
		// for dump count absolute cycles?
		if (vm->flags.dump == vm->total_cycle)	//do this before cycle to die or it breaks 
			cycle_dump(vm);
			
		if (vm->curr_cycle >= vm->cycle_to_die) // at start or at end?!?!
			if (cycle_checkup(vm))
				break ;
		
		// if (print_update)
			// print_game_state(vm);
		i++;
	}
	// print_game_state(vm);
	display_winner(vm);
	// free everything?
}
