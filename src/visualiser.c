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

void	n_print_one_cursor(t_vm *vm, t_cursor *cursor)
{
	int col;
	int y;
	int x;

	col = get_colour_ref(vm, cursor->pc);
	if (col)
		wattron(DISPLAY(0), A_REVERSE);
	y = cursor->pc / 64;
	x = cursor->pc % 64;
	n_putnbr_hex(vm, cursor->op_code, (x * 3) + 1, y + 1, col);
	if (col)
		wattroff(DISPLAY(0), A_REVERSE);
}

void	n_print_cursor(t_vm *vm)
{
	int			y;
	int			col;
	int			x;
	t_cursor	*cursor;
	t_list		*stack;
	
	stack = vm->cursor_stack->start;
	while (stack)
	{
		cursor = stack->content;
		n_print_one_cursor(vm, cursor);
		stack = stack->next;
	}
}

/*
** get_colour seems to not have wrapping protection
** i.e. if a player's program will wrap around to the start of the core mem
** However, without custom start locations, the first player will always start 
** at index 0, so wrap around will never be possible, and will error out
** beforehand if a player's program needs to wrap around
*/

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

	y = 1;
	i = 0;
	cunt = 0;
	while (y < OCTET)
	{
		x = 1;
		cunt = 0;
		while (cunt < OCTET)
		{
			colour = get_colour_ref(vm, i);
			n_putnbr_hex(vm, (unsigned char)vm->core[i], x, y, colour);
			x += 2;
			mvwprintw(DISPLAY(0), y, x, "%c", ' ');
			x++;
			i++;
			cunt++;
		}
		y++;
	}
	// refresh();
	// wrefresh(DISPLAY(0));
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
		wmove(DISPLAY(1),  i, 5);
		wclrtoeol(DISPLAY(1));
		mvwprintw(DISPLAY(1), i, 5, "Lives: %d", player->nbr_lives);
		box(DISPLAY(1), 0, 0);
		node = node->next;
		i++;
	}
}


void	n_print_life_info(t_vm *vm)
{
	t_life node;
	t_list *temp;
	node = vm->life_info;
	mvwprintw(DISPLAY(1), 30, 1, "Number of live calls: %d", node.nbr_live_calls);
}

void	n_print_cycles(t_vm *vm)
{
	mvwprintw(DISPLAY(1), 32, 1, "Total cycles: %d", vm->total_cycle);
	wmove(DISPLAY(1),  33, 1);
	wclrtoeol(DISPLAY(1));
	mvwprintw(DISPLAY(1), 33, 1, "Current cycle: %d", vm->curr_cycle);
	wmove(DISPLAY(1),  34, 1);
	wclrtoeol(DISPLAY(1));
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
	if (c == 'p')
		timeout(1);
	if (c == KEY_LEFT)
		vm->cwv.speed--;
	else if (c == KEY_RIGHT)
		vm->cwv.speed++;
}

void	n_display_winner(t_vm *vm, t_player *player)
{
	int		x;
	int		x2;
	int		y;
	int		y2;
	WINDOW	*display;
	getmaxyx(stdscr, y, x);
	display = newwin(y / 3, x / 3, (y / 5) / 2, (x / 5) / 2);
	getmaxyx(display, y, x);
	box(display, 0, 0);
	if (player)
		mvwprintw(display, (y / 2) / 2, (x / 2) / 2, "Winner is %s", player->name);
	else
		mvwprintw(display, (y / 2) / 2, (x / 2) / 2, "Everybody loses");
	mvwprintw(display, ((y / 2) / 2) + 1, (x / 2) / 2, "Press any key to quit");
	refresh();
	wrefresh(display);
	timeout(-1);
	getch();
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
	n_refresh_all(vm);
	timeout(vm->cwv.speed);
	c = getch();
	if (c == ' ')
	{
		timeout(-1);
		getch();
	}
	// 	c = getch();
	// if (c == ' ')
	// {
	// 	timeout(-1);
	// 	getch();
	// }
	// 	c = getch();
	// if (c == ' ')
	// {
	// 	timeout(-1);
	// 	getch();
	// }
	// c = getch();
	// if (c == ' ')
	// {
	// 	timeout(-1);
	// 	getch();
	// }
}

void	n_init_colour_ref(t_vm *vm)
{
	int	x;

	x = 0;
	ft_bzero(vm->cwv.colour_ref, MEM_SIZE);
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
	noecho();
	curs_set(0);
	n_init_sizes(vm);
	n_init_color_pairs();
	n_init_colour_ref(vm);
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