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

void		kill_players(t_vm *vm)
{
	t_player	*player;
	t_list		*node;
	
	node = vm->player_list->start;
	while(node)
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

/*
** Will end the game if all players are dead
*/

int		cycle_checkup(t_vm *vm)
{
	if (vm->life_info.nbr_live_calls >= NBR_LIVE ||
			vm->life_info.nbr_live_reached)
	{
		vm->life_info.nbr_checkups = 0;
		vm->cycle_to_die -= CYCLE_DELTA;		
		vm->life_info.nbr_live_reached = 1;
		kill_players(vm);
		if (vm->nbr_dead >= (int)vm->player_list->length - 1)
			return (1);
		else if (vm->cycle_to_die <= 0)
			return (1);
	}
	else if (vm->life_info.nbr_checkups >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->life_info.nbr_checkups = 0;
	}
	vm->curr_cycle = 0;
	vm->life_info.nbr_checkups++;
	// printf("cycle to die: %d\n", vm->cycle_to_die);
	// printf("cycle checkups: %d\n", vm->life_info.nbr_checkups);
	// printf("nbr live calls: %d\n", vm->life_info.nbr_live_calls);
	
	
	return (0);
}

/*
• Every CYCLE_TO_DIE cycles, the machine needs to make sure that each process
has executed at least one live since the last check. A process that does not abide
by this rule will be killed immediately with a virtual foamy bat (bonus for sound
effect!)
• If during one of those checkup we notice that there has been at least one NBR_LIVE
execution of live since the latest check up, we will decrease CYCLE_TO_DIE of
CYCLE_DELTA units.
*/
/*
CYCLE_TO_DIE: The VM must manage proprely different CYCLE_TO_DIE:
- A process that doesn't do at least one live during the
CYCLE_TO_DIE cycles must die.
- If during a CYCLE_TO_DIE period of time there is at least
NBR_LIVE live executed when the check-up is operated
CYCLE_TO_DIE must be decreased by CYCLE_DELTA.
- If during a check-up there has been no CYCLE_TO_DIE
since MAX_CHECKS check-ups, it's decreased.
- If during a check-up all processes are dead, the ga
*/
/*
It must check that every process calls the "live" instruction every CYCLE_TO_DIE.
• If after NBR_LIVE calls to the "live" instruction all the processes alive still are
alive,
• We decrement CYCLE_TO_DIE of CYCLE_DELTA units and we start again
until there are no more processes alive
• The last player who said "live" wins
*/

/*
after cycle to die cycles == check
each player must have 1 live call
move on to next turn

if nbr live calls occured:
	decrease cycle to di by delta
or  max checks has been reached
*/



/*
every cycle to death check everyone is alive
kill needed players
only decrease cycle to die if nbr lives is reached or max check
*/
