/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 11:44:23 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	sti par1,par2,par3
**	par1 = reg
**	par2 = dir or ind or reg
**	par3 = dir or reg
**	sti copies REG_SIZE bytes of par1 at address (par2 + par3)
**	Parameters 2 and 3 are indexes. If they are registers,
**	their contents are used as indexes.
*/

static void	sti3(t_vm *vm, t_cursor *cursor, t_ldi *store)
{
	if (cursor->encoding == RDD)
	{
		store->jump = 7;
		store->location_info += get_dir(3, vm, cursor, 1);
		store->location_info += get_dir(5, vm, cursor, 1);
	}
}

static void	sti2(t_vm *vm, t_cursor *cursor, t_ldi *store)
{
	if (cursor->encoding == RIR)
	{
		store->jump = 6;
		store->location_info += get_ind(3, vm, cursor);
		if (!(store->reg = get_reg(5, vm, cursor)))
			return ;
		store->location_info += *(store->reg);
	}
	else if (cursor->encoding == RDR)
	{
		store->jump = 6;
		store->location_info += get_dir(3, vm, cursor, 1);
		if (!(store->reg = get_reg(5, vm, cursor)))
			return ;
		store->location_info += *(store->reg);
	}
	else if (cursor->encoding == RID)
	{
		store->jump = 7;
		store->location_info += get_ind(3, vm, cursor);
		store->location_info += get_dir(5, vm, cursor, 1);
	}
	else
		sti3(vm, cursor, store);
}

static void	sti1(t_vm *vm, t_cursor *cursor, t_ldi *store)
{
	if (cursor->encoding == RRR)
	{
		store->jump = 5;
		if (!(store->reg = get_reg(3, vm, cursor)))
			return ;
		store->location_info += *(store->reg);
		if (!(store->reg = get_reg(4, vm, cursor)))
			return ;
		store->location_info += *(store->reg);
	}
	else if (cursor->encoding == RRD)
	{
		store->jump = 6;
		if (!(store->reg = get_reg(3, vm, cursor)))
			return ;
		store->location_info += *(store->reg);
		store->location_info += get_dir(4, vm, cursor, 1);
	}
	else
		sti2(vm, cursor, store);
}

int			cw_sti(t_vm *vm, t_cursor *cursor)
{
	int		*reg_info_toload;
	t_ldi	store;

	store.location_info = 0;
	store.jump = 1;
	sti1(vm, cursor, &store);
	reg_info_toload = get_reg(2, vm, cursor);
	if (store.jump > 1 && reg_info_toload)
	{
		store_core_int(*reg_info_toload,
						PC_PLUS(store.location_info % IDX_MOD),
							vm, cursor->player_num);
	}
	return (store.jump);
}
