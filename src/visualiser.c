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

void	n_print_one_cursor(t_vm *vm, t_cursor *cursor)
{
	int col;
	int y;
	int x;
	int x_y[2];

	col = get_colour_ref(vm, cursor->pc);
	if (col)
		wattron(DISPLAY(0), A_REVERSE);
	y = cursor->pc / 64;
	x = cursor->pc % 64;
	x_y[0] = (x * 3) + 1;
	x_y[1] = y + 1;
	n_putnbr_hex(vm, cursor->op_code, x_y, col);
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
	int			i;
	t_list		*player_node;
	t_player	*player;

	player_node = vm->player_list->start;
	i = 1;
	while (player_node)
	{
		player = player_node->content;
		if ((core_index >= player->start_loc) &&
			(core_index < (player->start_loc + player->program_size)))
			return (i);
		player_node = player_node->next;
		i++;
	}
	return (99);
}

/*
** The below declaration format of WINDOW * display is
** according to Norminette and not the Norme
*/

void	n_display_winner(t_vm *vm, t_player *player)
{
	int		x;
	int		y;

	WINDOW * display;
	getmaxyx(stdscr, y, x);
	y /= 2;
	x /= 2;
	display = newwin(15, 135, y - 15, x - 85);
	getmaxyx(display, y, x);
	box(display, 0, 0);
	if (player)
	{
		wattron(display, A_BOLD | COLOR_PAIR(player->col_num));
		mvwprintw(display, (y / 2) / 2, (x / 2) / 2, "%s is win", player->name);
		wattroff(display, A_BOLD | COLOR_PAIR(player->col_num));
	}
	else
		mvwprintw(display, (y / 2) / 2, (x / 2) / 2, "Lord Geff wins");
	mvwprintw(display, ((y / 2) / 2) + 1, (x / 2) / 2, "Press any key to quit");
	refresh();
	wrefresh(display);
	timeout(-1);
	getch();
}
