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

void	n_putnbr_hex(t_vm *vm, int byte, int x, int y, int col)
{	
	if (col)
		wattron(DISPLAY(0), COLOR_PAIR(col));
	mvwprintw(DISPLAY(0), y, x, "%c", BASE[((byte / 16) % 16)]);
	x += 1;
	mvwprintw(DISPLAY(0), y, x, "%c", BASE[(byte % 16)]);
	if (col)
		wattroff(DISPLAY(0), COLOR_PAIR(col));
}

void	n_init_windows(t_vm *vm, int win)
{
	int a[4];
	
	a[0] = vm->cwv.section[win].start_x;
	a[1] = vm->cwv.section[win].start_y;
	a[2] = vm->cwv.section[win].size_x;
	a[3] = vm->cwv.section[win].size_y;
	vm->cwv.window[win] = newwin(a[2], a[3], a[0], a[1]);
}

void	n_init_sizes(t_vm *vm)
{
	int		octet;

	vm->cwv.section[0].start_x = 0;
	vm->cwv.section[0].start_y = 0;
	vm->cwv.section[0].size_y = (OCTET * 3) + 2;
	vm->cwv.section[0].size_x = (OCTET + 4);

	vm->cwv.section[1].start_x = 0;
	vm->cwv.section[1].start_y = (OCTET * 3) + 3;
	vm->cwv.section[1].size_x = (OCTET / 2 + (OCTET / 6)) + 4;
	vm->cwv.section[1].size_y = 48;

	vm->cwv.section[2].start_x = (OCTET / 2 + (OCTET / 6)) + 4;
	vm->cwv.section[2].start_y = (OCTET * 3) + 3;
	vm->cwv.section[2].size_x = (OCTET - (OCTET / 2 + (OCTET / 6)));
	vm->cwv.section[2].size_y = 48;

	n_init_windows(vm, 0);
	n_init_windows(vm, 1);
	n_init_windows(vm, 2);
}

void	n_init_color_pairs()
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

void	n_refresh_all(t_vm *vm)
{
	refresh();
	wrefresh(DISPLAY(0));
	wrefresh(DISPLAY(1));
	wrefresh(DISPLAY(2));
}