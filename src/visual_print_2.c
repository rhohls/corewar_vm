/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_print_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:43:53 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 09:44:04 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	n_print_core(t_vm *vm)
{
	int i;
	int x;
	int y;
	int	count;
	int colour;

	y = 1;
	i = 0;
	while (y <= OCTET)
	{
		x = 1;
		count = 0;
		while (count < OCTET)
		{
			colour = get_colour_ref(vm, i);
			n_putnbr_hex(vm, (unsigned char)vm->core[i++], x, y, colour);
			x += 2;
			mvwprintw(DISPLAY(0), y, x++, "%c", ' ');
			count++;
		}
		y++;
	}
	n_refresh_all(vm);
}

void	n_print_player_info(t_vm *vm, t_player *player, int *i, int *col)
{
	mvwprintw(DISPLAY(1), (*i)++, 1, "Player %d:", player->player_num);
	if (player->alive)
		wattron(DISPLAY(1), A_BOLD | COLOR_PAIR(*col));
	mvwprintw(DISPLAY(1), (*i)++, 5, "%s", player->name);
	if (player->alive)
		wattroff(DISPLAY(1), A_BOLD | COLOR_PAIR((*col)++));
	wmove(DISPLAY(1), *i, 5);
	wclrtoeol(DISPLAY(1));
	mvwprintw(DISPLAY(1), (*i)++, 5,
		"Player is %s", player->alive ? "alive" : "dead");
	mvwprintw(DISPLAY(1), (*i)++, 5, "Size: %d bytes", player->program_size);
	wmove(DISPLAY(1), *i, 5);
	wclrtoeol(DISPLAY(1));
	mvwprintw(DISPLAY(1), (*i)++, 5, "Lives: %d", player->nbr_lives);
}

void	n_print_names(t_vm *vm)
{
	int			i;
	int			col;
	t_list		*node;
	t_player	*player;

	i = 15;
	col = 1;
	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		player->col_num = col;
		n_print_player_info(vm, player, &i, &col);
		i++;
		node = node->next;
	}
	box(DISPLAY(1), 0, 0);
}