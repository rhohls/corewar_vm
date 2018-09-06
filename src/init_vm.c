/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:35 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/06 12:50:41 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		size_balance(char *board, t_list *players, unsigned int size)
{
	t_list			*start;
	u_int			offset;
	int				i;
	int				x;

	offset = (MEM_SIZE - size) / MAX_PLAYERS;
	start = players;
	x = 0;
	while (players)
	{
		i = 0;
		while (((t_player *)(players->content))->program[i])
		{
			board[x] = ((t_player *)(players->content))->program[i];
			x++;
			i++;
		}
		x += offset;
		players = players->next;
	}
	players = start;
}

void		*charge_players(char *board, t_list *players)
{
	unsigned int	size;
	t_list 			*start;
	
	size = 0;
	start = players;
	while (players)
	{
		size += ((t_player *)(players->content))->program_size;
		players = players->next;
	}
	players = start;
	size_balance(board, players, size);
	return (board);
}