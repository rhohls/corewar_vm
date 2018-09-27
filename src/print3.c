/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:17:48 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 16:17:49 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_board(unsigned char const *core, size_t size, int fd)
{
	size_t	ind;
	size_t	a;
	size_t	stop;

	stop = 64;
	ind = 0;
	while (ind < size)
	{
		a = 0;
		while (a < stop && a + ind < size)
		{
			putnbr_hex(*(core + ind + a), 2, fd);
			write(fd, " ", 1);
			a++;
		}
		write(fd, "\n", 1);
		ind += stop;
	}
}

void	print_player_live(t_vm *vm, int fd)
{
	t_list		*node;
	t_player	*player;

	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		ft_dprintf(fd, "Player: \"%s\" number: %i ", player->name,
					player->player_num);
		if (player->alive == 0)
			ft_dprintf(fd, "is dead\n");
		else
			ft_dprintf(fd, "has %d lives\n", player->nbr_lives);
		node = node->next;
	}
}

void	print_cycle_info(t_vm *vm, int fd)
{
	ft_dprintf(fd, "Current cycle: %d\t", vm->curr_cycle);
	ft_dprintf(fd, "Cycle to die: %d\t", vm->cycle_to_die);
	ft_dprintf(fd, "Cycle delta: %d\n", CYCLE_DELTA);
}
