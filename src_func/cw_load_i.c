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

int	cw_load_i(t_vm *vm, t_cursor *cursor, int long_ld)
{
	//printf("- in ldi -\n");
	int		info_to_load;
	int		location_info;
	int		indirect;
	int		*reg_to_load;
	int		*reg;
	int 	jump;

	jump = 1;
	location_info = 0;
	// , vm, cursor
	if (cursor->encoding == RRR)
	{
		jump = 5;
		if (!(reg = get_reg(2, vm, cursor)))
			return (jump);
		location_info += *(reg);
		if (!(reg = get_reg(3, vm, cursor)))
			return (jump);
		location_info += *(reg);
		reg_to_load = get_reg(4, vm, cursor);
	}
	else if (cursor->encoding == DRR)
	{
		jump = 6;
		location_info += get_dir(2, vm, cursor, 1);
		if (!(reg = get_reg(4, vm, cursor)))
			return (jump);
		location_info += *(reg);
		reg_to_load = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == IRR)
	{
		jump = 6;
		
		if (long_ld)
			location_info += get_ind_nomod(2, vm, cursor);
		else
			location_info += get_ind(2, vm, cursor);
		if (!(reg = get_reg(4, vm, cursor)))
			return (jump);
		location_info += *(reg);
		reg_to_load = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == RDR)
	{
		jump = 6;
		if (!(reg = get_reg(2, vm, cursor)))
			return (jump);
		location_info += *(reg);
		location_info += get_dir(3, vm, cursor, 1);
		reg_to_load = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == DDR)
	{
		jump = 7;
		location_info += get_dir(2, vm, cursor, 1);
		location_info += get_dir(5, vm, cursor, 1);
		reg_to_load = get_reg(6, vm, cursor);
	}
	else if (cursor->encoding == IDR)
	{
		jump = 7;
		if (long_ld)
			location_info += get_ind_nomod(2, vm, cursor);
		else
			location_info += get_ind(2, vm, cursor);
		location_info += get_dir(5, vm, cursor, 1);
		reg_to_load = get_reg(6, vm, cursor);
	}
	
	if (jump > 1 && reg_to_load)
	{
		if (!long_ld)
			location_info = location_info % IDX_MOD;
		info_to_load = get_core_int(PC_PLUS(location_info), vm);
		*reg_to_load = info_to_load;
		if (*reg_to_load)
			cursor->carry = 1;
	}
	return (jump);
}