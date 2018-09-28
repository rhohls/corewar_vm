/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:46:44 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 15:46:45 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		n_get_col(t_vm *vm, int num)
{
	t_list		*node;
	t_player	*player;

	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		if (player->player_num == num)
			return (player->col_num);
		node = node->next;
	}
	return (num);
}

void	n_print_stored_int(int core_dest_start, t_vm *vm, int player_num)
{
	int			i;
	int			x;
	t_list		*node;
	t_player	*player;

	i = 0;
	node = vm->player_list->start;
	player = node->content;
	x = n_get_col(vm, player_num);
	while (i < 4)
	{
		vm->cwv.colour_ref[core_dest_start + i] = x;
		i++;
	}
	box(DISPLAY(0), 0, 0);
	n_refresh_all(vm);
}

void	store_core_int(int number, int core_dst_start, t_vm *vm, int p_num)
{
	char *num;

	num = (char *)(&number);
	vm->core[WRAP(core_dst_start + 0)] = num[3];
	vm->core[WRAP(core_dst_start + 1)] = num[2];
	vm->core[WRAP(core_dst_start + 2)] = num[1];
	vm->core[WRAP(core_dst_start + 3)] = num[0];
	if (vm->flags.visual && vm->cwv.mode)
		n_print_stored_int(core_dst_start, vm, p_num);
}
