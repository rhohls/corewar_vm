/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:30:54 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 11:21:20 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	display_winner(t_vm *vm)
{
	t_player	*player;

	player = get_player(vm, vm->life_info.last_live_playernum);
	if (player)
	{
		if (vm->cwv.mode)
			n_display_winner(vm, player);
		else
			ft_printf("The winner is ...\n\tPlayer %d with name \"%s\"\n",
						player->player_num, player->name);
	}
	else
	{
		if (vm->cwv.mode)
			n_display_winner(vm, player);
		else
			ft_printf("Lord Geff wins\n");
	}
}

void	dump_to_file(int cycle_number, t_vm *vm)
{
	int fd;
	char *file_name;

	file_name = ft_itoa(cycle_number);
	file_name = ft_strjoinfree(file_name, ".dump");
	fd = open(file_name, O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU);
	if (vm->flags.verbose)
		print_game_state(vm, fd);
	else
		print_board_location((const unsigned char *)(&(vm->core[0])), MEM_SIZE, fd);
	free(file_name);
}

void	n_dump_popup(t_vm *vm)
{
	int		y;
	int		x;
	char	str[128];
	WINDOW *display;

	getmaxyx(stdscr, y, x);
	y /= 2;
	x /= 2;
	display = newwin(15, 135, y - 15, x - 85);
	getmaxyx(display, y, x);
	box(display, 0, 0);
	if (vm->flags.contin)
	{
		mvwprintw(display, ((y / 2) / 2) + 1, (x / 2) / 2, "Please enter the next cycle to dump at, or press Enter to continue");
		wmove(display, ((y / 2) / 2) + 3, (x / 2) / 2);
		wgetstr(display, str);
		vm->flags.dump = ft_atoi(str);
		refresh();
		wrefresh(display);
		n_print_game_state(vm);
		timeout(-1);
		getch();
	}
	else
	{
		endwin();
		if (vm->flags.verbose)
			print_game_state(vm, 0);
		else
			print_board_location((const unsigned char *)(&(vm->core[0])), MEM_SIZE, 0);
		exit(0);
	}
}

void	cycle_dump(t_vm *vm)
{
	char *line;
	char c;

	if (vm->flags.visual)
	{
		dump_to_file(vm->flags.dump, vm);
		n_dump_popup(vm);
	}
	else
	{
		if (vm->flags.verbose)
			print_game_state(vm, 0);
		else
			print_board_location((const unsigned char *)(&(vm->core[0])), MEM_SIZE, 0);
		if (vm->flags.contin)
		{
			ft_putendl("Please enter the next cycle to dump at, or 0 to continue to game end");
			get_next_line(0, &line);
			vm->flags.dump = ft_atoi_long(line);
		}
		else
			exit(0);
	}
}

void	vm_loop(t_vm *vm)
{
	int print_update;

	while (1)
	{
		if (vm->cwv.mode)
		{
			n_key_get(vm);
			n_print_game_state(vm);
		}
		print_update = 0;
		if (vm->flags.update)
			printf("Total cycles: %ld Curr cycles: %d Cycle to die: %d\n", vm->total_cycle, vm->curr_cycle, vm->cycle_to_die);
		incr_all_cursor(vm, &print_update);
		vm->curr_cycle++;
		vm->total_cycle++;
		if (vm->flags.dump == vm->total_cycle)
			cycle_dump(vm);
		if (vm->curr_cycle >= vm->cycle_to_die)
			if (cycle_checkup(vm))
				break ;
		if (print_update && vm->flags.update)
			print_game_state(vm, 0);
	}
	display_winner(vm);
}
