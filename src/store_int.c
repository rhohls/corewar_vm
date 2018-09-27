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

void	n_print_stored_int(int core_dest_start, t_vm *vm, int player_num)
{
	int	i;
	int	x;
	int y;

	i = 0;
	y = core_dest_start / 64;
	x = core_dest_start % 64;
	while (i < 4)
	{
		vm->cwv.colour_ref[core_dest_start + i] = player_num;
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
