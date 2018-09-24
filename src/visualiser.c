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


static void	n_putnbr_hex(t_vm *vm, int octet, int x, int y)
{
	// char const *base = "0123456789abcdef";
	
	mvwprintw(DISPLAY(0), y, x, "%c", BASE[((octet/16) % 16)]);
	// mvwprintw(DISPLAY(0), y, *x, "%d", ((octet/16) % 16));
	// mvwprintw(DISPLAY(1), 1, 1, "%d", ((octet/16) % 16));
	x += 1;
	mvwprintw(DISPLAY(0), y, x, "%c", BASE[(octet % 16)]);
	// mvwprintw(DISPLAY(1), 1, 4, "%c", BASE[(octet % 16)]);

	// mvwprintw(DISPLAY(1), 1, 4, "%d", BASE[16]);
	// mvwprintw(DISPLAY(0), y, *x, "%d", (octet % 16));

	
}

void	n_print_cursor(t_vm *vm, int cursor)
{
	int y;
	
	y = 1;
	while (cursor > OCTET)
	{
		cursor /= OCTET;
		y++;
	}
	mvwprintw(DISPLAY(1), 1, 1, "c: %d y: %d", cursor, y);
	attron(A_REVERSE);
	mvwprintw(DISPLAY(0), y, (cursor * 3), "");
	cursor++;
	mvwprintw(DISPLAY(0), y, (cursor * 3), "");
	attroff(A_REVERSE);
	refresh();
	wrefresh(DISPLAY(1));
}

void	n_print_core(t_vm *vm)
{
	int i;
	int x;
	int y;
	int	cunt;

	x = 1;
	y = 1;
	i = 0;
	cunt = 0;
	werase(DISPLAY(0));
	box(DISPLAY(0), 0, 0);
	while (y < OCTET)
	{
		x = 1;
		cunt = 0;
		while (cunt < OCTET)
		{
			n_putnbr_hex(vm, (unsigned char)vm->core[i], x, y);
			x += 2;
			// if (x % 3 == 0 && x > 0)
			mvwprintw(DISPLAY(0), y, x, "%c", ' ');
			x++;
			i++;
			cunt++;
		}
		y++;
	}
	refresh();
	wrefresh(DISPLAY(0));
}

void	n_print_names(t_vm *vm)
{
	int			i;
	int			col;
	t_list		*node;
	t_player	*player;

	i = 2;
	col = 1;
	node = vm->player_list->start;
	box(DISPLAY(1), 0, 0);
	while (node)
	{
		player = node->content;
		mvwprintw(DISPLAY(1), i++, 1, "Player %d:", player->player_num);
		wattron(DISPLAY(1), A_BOLD | COLOR_PAIR(col));
		mvwprintw(DISPLAY(1), i++, 5, "%s", player->name);
		wattroff(DISPLAY(1), A_BOLD | COLOR_PAIR(col++));
		mvwprintw(DISPLAY(1), i++, 5, "Size: %d bytes", player->program_size);
		mvwprintw(DISPLAY(1), i, 5, "Lives: %d", player->nbr_lives);
		node = node->next;
		i++;
	}
}

void	n_print_life_info(t_vm *vm)
{
	t_life node;
	t_list *temp;

	node = vm->life_info;
	mvwprintw(DISPLAY(1), 20, 1, "Live calls: %d", node.nbr_live_calls);
}

void	n_print_cycles(t_vm *vm)
{
	mvwprintw(DISPLAY(1), SECTION(1).size_x / 2 - 1, 1, "Total cycles: %d", vm->total_cycle);
	wmove(DISPLAY(1),  (SECTION(1).size_x / 2) + 15, 1);
	wclrtobot(DISPLAY(1));
	mvwprintw(DISPLAY(1), SECTION(1).size_x / 2, 1, "Current cycle: %d", vm->curr_cycle);
	mvwprintw(DISPLAY(1), (SECTION(1).size_x / 2) + 1, 1, "Cycles to die: %d", vm->cycle_to_die);
	mvwprintw(DISPLAY(1), (SECTION(1).size_x / 2) + 2, 1, "Cycle delta: %d", CYCLE_DELTA);
}

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

void	init_color_pairs()
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

void	n_print_game_state(t_vm *vm)
{
	n_print_core(vm);
	n_print_names(vm);
	n_print_cycles(vm);
	n_print_life_info(vm);
	timeout(vm->cwv.speed);
	getch();
	n_refresh_all(vm);
}

void	init_curses(t_vm *vm)
{
	vm->cwv.mode = 1;
	vm->cwv.speed = 6;
	initscr();
	// cbreak();
	// raw();
	noecho();
	curs_set(0);
	init_sizes(vm);
	init_color_pairs();
	box(DISPLAY(0), 0, 0);
	box(DISPLAY(1), 0, 0);
	box(DISPLAY(2), 0, 0);
	mvwprintw(DISPLAY(1), 1, 14, "CORE WAR");
	mvwprintw(DISPLAY(2), 1, 14, "CORE CHAT");
	n_print_game_state(vm);
}