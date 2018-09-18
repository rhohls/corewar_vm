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
	t_list		*node;
	
	node = vm->player_list->start;
	while(node)
	{
		player = node->content;
		if (player->alive == 1)
		{
			ft_printf("The winer is ...\n\tPlayer \"%s\" number: %d\n", player->name,
						player->player_num);
			break ;
		}
		node = node->next;
	}	
}

void	vm_loop(t_vm *vm)
{
	int i = 0;
	while(i < 100)
	{
		printf("Cycle: %d\n", vm->curr_cycle);
		incr_all_cursor(vm);
		vm->curr_cycle++;
		if (vm->curr_cycle == vm->cycle_death)
			if (cycle_death(vm))
				break ;
		// print_game_state(vm);
		i++;
	}
	display_winner(vm);
	// free everything?
}

