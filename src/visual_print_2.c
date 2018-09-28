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
	int	count;
	int colour;
	int x_y[2];

	x_y[1] = 1;
	i = 0;
	while (x_y[1] <= OCTET)
	{
		x_y[0] = 1;
		count = 0;
		while (count < OCTET)
		{
			colour = get_colour_ref(vm, i);
			n_putnbr_hex(vm, (unsigned char)vm->core[i++], x_y, colour);
			x_y[0] += 2;
			mvwprintw(DISPLAY(0), x_y[1], x_y[0], "%c", ' ');
			x_y[0]++;
			count++;
		}
		x_y[1]++;
	}
	n_refresh_all(vm);
}

void	n_print_player_info(t_vm *vm, t_player *player, int *i)
{
	mvwprintw(DISPLAY(1), (*i)++, 1, "Player %d:", player->player_num);
	if (player->alive)
		wattron(DISPLAY(1), A_BOLD | COLOR_PAIR(player->col_num));
	mvwprintw(DISPLAY(1), (*i)++, 5, "%s", player->name);
	if (player->alive)
		wattroff(DISPLAY(1), A_BOLD | COLOR_PAIR(player->col_num));
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
	t_list		*node;
	t_player	*player;

	i = 15;
	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		n_print_player_info(vm, player, &i);
		i++;
		node = node->next;
	}
	box(DISPLAY(1), 0, 0);
}
