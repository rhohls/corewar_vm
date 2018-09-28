/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 08:30:37 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 08:32:54 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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

void	n_init_color_pairs(void)
{
	start_color();
	init_color(99, 180, 180, 180);
	init_pair(99, 99, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

void	n_init_colour_ref(t_vm *vm)
{
	int	x;

	x = 0;
	ft_memset(vm->cwv.colour_ref, 99, MEM_SIZE);
	while (x < MEM_SIZE)
	{
		vm->cwv.colour_ref[x] = get_colour(vm, x);
		x++;
	}
}

void	n_init_curses(t_vm *vm)
{
	if (vm->flags.visual)
		vm->cwv.mode = 1;
	else
		vm->cwv.mode = 0;
	vm->cwv.speed = 0;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	n_init_sizes(vm);
	n_init_color_pairs();
	n_init_colour_ref(vm);
	n_assign_col(vm);
	n_print_game_state(vm);
}
