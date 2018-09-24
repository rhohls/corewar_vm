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

void	n_print_cursor(t_vm *vm)
{
	int			y;
	int			col;
	int			hold;
	t_cursor	*cursor;
	t_list		*stack;
	
	int	i;

	i = 0;
	stack = vm->cursor_stack->start;
	while (stack)
	{
		cursor = stack->content;
		col = player_num_to_colour_num(vm, cursor->player_num);
		y = 1;
		hold = cursor->pc;
		while (hold > OCTET)
		{
			hold /= OCTET;
			y++;
		}
		if (col)
			wattron(DISPLAY(0), A_REVERSE | COLOR_PAIR(col));
		n_putnbr_hex(vm, vm->core[hold], y, hold, col);
		wattroff(DISPLAY(0), A_REVERSE | COLOR_PAIR(col));
		wmove(DISPLAY(2), i, 2);
		wclrtoeol(DISPLAY(2));
		mvwprintw(DISPLAY(2), i, 2, "cursor no: |%d|\tpc: |%d|", i, cursor->pc);
		box(DISPLAY(2), 0, 0);
		i++;
		stack = stack->next;
	}
}

int		get_colour(t_vm *vm, int core_index)
{

	int 		i;
	t_list		*player_node;
	t_player	*player;

	player_node = vm->player_list->start;
	i = 1;

	while (player_node)
	{
		player = player_node->content;
		if ((core_index >= player->start_location) && 
			(core_index <= (player->start_location + player->program_size)))
			return (i);
		player_node = player_node->next;
		i++;
	}
	return (0);
}

void	n_print_core(t_vm *vm)
{
	int i;
	int x;
	int y;
	int	cunt;
	int colour;

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
			colour = get_colour(vm, i);
			// wattron(DISPLAY(2), COLOR_PAIR(colour));
			// mvwprintw(DISPLAY(2), colour, 1, "%d", colour);
			// wattroff(DISPLAY(2), COLOR_PAIR(colour));
			n_putnbr_hex(vm, (unsigned char)vm->core[i], x, y, colour);
			x += 2;
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

	i = 4;
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
	mvwprintw(DISPLAY(1), 30, 1, "Live calls: %d", node.nbr_live_calls);
}

void	n_print_cycles(t_vm *vm)
{
	mvwprintw(DISPLAY(1), 32, 1, "Total cycles: %d", vm->total_cycle);
	wmove(DISPLAY(1),  33, 1);
	wclrtoeol(DISPLAY(1));
	mvwprintw(DISPLAY(1), 33, 1, "Current cycle: %d", vm->curr_cycle);
	mvwprintw(DISPLAY(1), 34, 1, "Cycles to die: %d", vm->cycle_to_die);
	mvwprintw(DISPLAY(1), 35, 1, "Cycle delta: %d", CYCLE_DELTA);
	mvwprintw(DISPLAY(1), 36, 1, "Max checks: %d", MAX_CHECKS);
	box(DISPLAY(1), 0, 0);
}

void	n_key_get(t_vm *vm)
{
	int c;

	timeout(1);
	c = getch();
	if (c == KEY_LEFT)
		vm->cwv.speed--;
	else if (c == KEY_RIGHT)
		vm->cwv.speed++;
}

void	n_print_game_state(t_vm *vm)
{
	char c;

	// n_key_get(vm);
	n_print_core(vm);
	n_print_names(vm);
	n_print_cycles(vm);
	n_print_life_info(vm);
	n_print_cursor(vm);
	timeout(vm->cwv.speed);
	c = getch();
	if (c == ' ')
	{
		timeout(-1);
		getch();
	}
	n_refresh_all(vm);
}

void	n_init_curses(t_vm *vm)
{
	vm->cwv.mode = 1;
	vm->cwv.speed = 1;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	n_init_sizes(vm);
	n_init_color_pairs();
	box(DISPLAY(0), 0, 0);
	box(DISPLAY(1), 0, 0);
	box(DISPLAY(2), 0, 0);
	wattron(DISPLAY(1), A_UNDERLINE);
	mvwprintw(DISPLAY(1), 1, 14, "CORE WAR");
	wattroff(DISPLAY(1), A_UNDERLINE);
	mvwprintw(DISPLAY(2), 1, 14, "CORE CHAT");
	mvwprintw(DISPLAY(1), 2, 1, "MEM_SIZE: %d bytes", MEM_SIZE);
	n_print_game_state(vm);
}