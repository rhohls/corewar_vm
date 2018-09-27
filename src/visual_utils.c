/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:38:44 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/24 10:39:04 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	n_putnbr_hex(t_vm *vm, int byte, int *x_y, int col)
{
	if (col)
		wattron(DISPLAY(0), COLOR_PAIR(col));
	mvwprintw(DISPLAY(0), x_y[1], x_y[0], "%c", BASE[((byte / 16) % 16)]);
	mvwprintw(DISPLAY(0), x_y[1], x_y[0] + 1, "%c", BASE[(byte % 16)]);
	if (col)
		wattroff(DISPLAY(0), COLOR_PAIR(col));
}

void	n_pause(t_vm *vm)
{
	mvwprintw(DISPLAY(1), 2, 1, "Game state: paused ");
	refresh();
	wrefresh(DISPLAY(1));
	timeout(-1);
	getch();
	mvwprintw(DISPLAY(1), 2, 1, "Game state: running");
}

void	n_key_get(t_vm *vm)
{
	int	c;
	int	mult;

	timeout(0);
	c = getch();
	if (c == 27)
	{
		endwin();
		exit(0);
	}
	if (c == ' ')
		n_pause(vm);
	mult = vm->cwv.speed < 100000 ? 5000 : 10000;
	if (c == KEY_LEFT)
		vm->cwv.speed += mult;
	else if (c == KEY_RIGHT && vm->cwv.speed - mult >= 0)
		vm->cwv.speed -= mult;
	else if (c == KEY_DOWN)
		vm->cwv.speed = 0;
	flushinp();
	wmove(DISPLAY(1), 4, 1);
	wclrtoeol(DISPLAY(1));
	c = 1000;
	mvwprintw(DISPLAY(1), 4, 1, "Game speed delay: %dms", vm->cwv.speed / c);
	box(DISPLAY(1), 0, 0);
}

void	n_print_game_state(t_vm *vm)
{
	char c;

	n_print_core(vm);
	n_print_cycles(vm);
	n_print_names(vm);
	n_print_life_info(vm);
	n_print_cursor(vm);
	n_refresh_all(vm);
	usleep(vm->cwv.speed);
}

void	n_refresh_all(t_vm *vm)
{
	refresh();
	wrefresh(DISPLAY(0));
	wrefresh(DISPLAY(1));
	wrefresh(DISPLAY(2));
}
