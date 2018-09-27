/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 10:50:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	ldi par1, par2, par3
**	par1 = dir or ind or reg_to_load
**	par2 = reg_to_load or dir
**	par3 = reg_to_load
**
**	takes values at par1, and par2
**	add together to find location of info
**	store info at location into par 3
**	This operation modifies the carry.
*/

static void	ldi_4(t_vm *vm, t_cursor *cursor, int long_ld, t_ldi *ldi)
{
	if (cursor->encoding == DDR)
	{
		ldi->jump = 7;
		ldi->location_info += get_dir(2, vm, cursor, 1);
		ldi->location_info += get_dir(4, vm, cursor, 1);
		ldi->reg_to_load = get_reg(6, vm, cursor);
	}
	else if (cursor->encoding == IDR)
	{
		ldi->jump = 7;
		if (long_ld)
			ldi->location_info += get_ind_nomod(2, vm, cursor);
		else
			ldi->location_info += get_ind(2, vm, cursor);
		ldi->location_info += get_dir(4, vm, cursor, 1);
		ldi->reg_to_load = get_reg(6, vm, cursor);
	}
}

static void	ldi_3(t_vm *vm, t_cursor *cursor, int long_ld, t_ldi *ldi)
{
	if (cursor->encoding == IRR)
	{
		ldi->jump = 6;
		if (long_ld)
			ldi->location_info += get_ind_nomod(2, vm, cursor);
		else
			ldi->location_info += get_ind(2, vm, cursor);
		if (!(ldi->reg = get_reg(4, vm, cursor)))
			return ;
		ldi->location_info += *(ldi->reg);
		ldi->reg_to_load = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == RDR)
	{
		ldi->jump = 6;
		if (!(ldi->reg = get_reg(2, vm, cursor)))
			return ;
		ldi->location_info += *(ldi->reg);
		ldi->location_info += get_dir(3, vm, cursor, 1);
		ldi->reg_to_load = get_reg(5, vm, cursor);
	}
	else
		ldi_4(vm, cursor, long_ld, ldi);
}

static void	ldi_2(t_vm *vm, t_cursor *cursor, int long_ld, t_ldi *ldi)
{
	if (cursor->encoding == RRR)
	{
		ldi->jump = 5;
		if (!(ldi->reg = get_reg(2, vm, cursor)))
			return ;
		ldi->location_info += *(ldi->reg);
		if (!(ldi->reg = get_reg(3, vm, cursor)))
			return ;
		ldi->location_info += *(ldi->reg);
		ldi->reg_to_load = get_reg(4, vm, cursor);
	}
	if (cursor->encoding == DRR)
	{
		ldi->jump = 6;
		ldi->location_info += get_dir(2, vm, cursor, 1);
		if (!(ldi->reg = get_reg(4, vm, cursor)))
			return ;
		ldi->location_info += *(ldi->reg);
		ldi->reg_to_load = get_reg(5, vm, cursor);
	}
	else
		ldi_3(vm, cursor, long_ld, ldi);
}

int			cw_load_i(t_vm *vm, t_cursor *cursor, int long_ld)
{
	t_ldi	ldi;

	ldi.jump = 1;
	ldi.location_info = 0;
	ldi_2(vm, cursor, long_ld, &ldi);
	if (ldi.jump > 1 && ldi.reg_to_load)
	{
		if (!long_ld)
			ldi.location_info = ldi.location_info % IDX_MOD;
		ldi.info_to_load = get_core_int(PC_PLUS(ldi.location_info), vm);
		*(ldi.reg_to_load) = ldi.info_to_load;
		cursor->carry = ldi.info_to_load == 0 ? 0 : 1;
	}
	return (ldi.jump);
}
