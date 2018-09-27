/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 08:38:41 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 08:38:51 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	n_print_life_info(t_vm *vm)
{
	t_life node;
	t_list *temp;

	node = vm->life_info;
	box(DISPLAY(1), 0, 0);
	mvwprintw(DISPLAY(1), 6, 1, "Number of live calls:\t%d",
		node.nbr_live_calls);
	mvwprintw(DISPLAY(1), 7, 1,
		"Number of processes:\t%d", vm->cursor_stack->length);
	refresh();
	wrefresh(DISPLAY(1));
}

void	n_print_cycles(t_vm *vm)
{
	int i;

	i = 9;
	wmove(DISPLAY(1), i, 0);
	wclrtobot(DISPLAY(1));
	mvwprintw(DISPLAY(1), i++, 1, "Total cycles:\t\t%d", vm->total_cycle);
	mvwprintw(DISPLAY(1), i++, 1, "Current cycle:\t\t%d", vm->curr_cycle);
	mvwprintw(DISPLAY(1), i++, 1, "Cycles to die:\t\t%d", vm->cycle_to_die);
	mvwprintw(DISPLAY(1), i++, 1, "Cycle delta:\t\t%d", CYCLE_DELTA);
	mvwprintw(DISPLAY(1), i++, 1, "Max checks:\t\t%d", MAX_CHECKS);
	box(DISPLAY(1), 0, 0);
}
