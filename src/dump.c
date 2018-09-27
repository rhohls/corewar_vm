/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:56:56 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 15:56:57 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		n_dump(t_vm *vm, WINDOW *display, int x, int y)
{
	int		i;
	char	str[128];

	mvwprintw(display, ((y / 2) / 2) + 1, (x / 2) / 2,
		"Please enter the next cycle to dump at, or press Enter to continue");
	wmove(display, ((y / 2) / 2) + 3, (x / 2) / 2);
	wgetstr(display, str);
	i = ft_atoi(str);
	refresh();
	wrefresh(display);
	n_print_game_state(vm);
	timeout(-1);
	getch();
	return (i);
}
