/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:39:11 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/19 10:39:22 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include "../includes/cwv.h"

void	init_windows(t_vm *vm, int win)
{
	int a[4];
	
	a[0] = vm->cwv.section[win].start_x;
	a[1] = vm->cwv.section[win].start_y;
	a[2] = vm->cwv.section[win].size_x;
	a[3] = vm->cwv.section[win].size_y;
	vm->cwv.window[win] = newwin(a[2], a[3], a[0], a[1]);
}

void	init_sizes(t_vm *vm)
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

	init_windows(vm, 0);
	init_windows(vm, 1);
	init_windows(vm, 2);
}

void	init_curses(t_vm *vm)
{
	vm->cwv.mode = 1;
	initscr();
	cbreak();
	// raw();
	// noecho();
	curs_set(0);
	init_sizes(vm);
	box(DISPLAY(0), 0, 0);
	box(DISPLAY(1), 0, 0);
	box(DISPLAY(2), 0, 0);
	refresh();
	wrefresh(DISPLAY(0));
	wrefresh(DISPLAY(1));
	wrefresh(DISPLAY(2));
	getch();
	mvwprintw(DISPLAY(0), 1, 1, "Hello there");
	refresh();
	wrefresh(DISPLAY(0));
	getch();
}