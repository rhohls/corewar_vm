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

void	init_windows(t_visual *cwv, int win)
{
	int a[4];
	
	a[0] = cwv->section[win].start_x;
	a[1] = cwv->section[win].start_y;
	a[2] = cwv->section[win].size_x;
	a[3] = cwv->section[win].size_y;
	cwv->window[win] = newwin(a[2], a[3], a[0], a[1]);
}

void	init_sizes(t_visual *cwv)
{
	cwv->section[0].start_x = 0;
	cwv->section[0].start_y = 0;
	cwv->section[0].size_y = (OCTET * 3) + 2;
	cwv->section[0].size_x = (OCTET + 4);

	cwv->section[1].start_x = 0;
	cwv->section[1].start_y = (OCTET * 3) + 2;
	cwv->section[1].size_x = OCTET + 4;
	cwv->section[1].size_y = 3;

	init_windows(cwv, 0);
	init_windows(cwv, 1);
}

void	init_curses(t_visual *cwv)
{
	cwv->mode = 1;
	initscr();
	cbreak();
	// raw();
	// noecho();
	curs_set(0);
	init_sizes(cwv);
}