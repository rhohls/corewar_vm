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
	
	player = get_player(vm, vm->life_info.last_live_playernum);
	ft_printf("The winer is ...\n\tPlayer %d with name \"%s\"\n", player->player_num, player->name);
						
	// t_player	*player;
	// t_list		*node;
	
	// node = vm->player_list->start;
	// while(node)
	// {
	// 	player = node->content;
	// 	if (player->alive == 1)
	// 	{
	// 		ft_printf("The winer is ...\n\tPlayer \"%s\" number: %d\n", player->name,
	// 					player->player_num);
	// 		break ;
	// 	}
	// 	node = node->next;
	// }	
}

void	vm_loop(t_vm *vm)
{
	int i = 0;
	int print_update;

	print_game_state(vm);
	printf("---------int at %d -----\n", get_half_c_int(1, vm));
	while(1)
	{
		print_update = 0;
		printf("Cycle: %d\n", vm->curr_cycle);
		incr_all_cursor(vm, &print_update);
		vm->curr_cycle++;
		if (vm->curr_cycle >= vm->cycle_to_die)
			if (cycle_checkup(vm))
				break ;
		// if (print_update)
		// 	print_game_state(vm);
		i++;
	}
	print_game_state(vm);
	
	display_winner(vm);
	// free everything?
}

