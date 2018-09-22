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

int	cw_ldi(t_vm *vm, t_cursor *cursor)
{
	// printf("- in ldi -\n");
	int		info_to_load;
	int		location_info;
	int		*reg_to_load;
	int		*reg;
	int 	jump;

	jump = 1;
	location_info = 0;
	
	if (cursor->encoding == RRR)
	{
		jump = 5;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(2))))
			return (jump);
		location_info += *(reg);
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(3))))
			return (jump);
		location_info += *(reg);
		reg_to_load = get_reg(cursor, CORE_PC_PLUS(4));
	}
	else if (cursor->encoding == IRR || cursor->encoding == DRR)
	{
		jump = 6;
		location_info += get_half_c_int(CORE_PC_PLUS(2), vm);
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(4))))
			return (jump);
		location_info += *(reg);
		reg_to_load = get_reg(cursor, CORE_PC_PLUS(5));
	}
	else if (cursor->encoding == RDR)
	{
		jump = 6;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(2))))
			return (jump);
		location_info += *(reg);
		location_info += get_half_c_int(CORE_PC_PLUS(3), vm);
		reg_to_load = get_reg(cursor, CORE_PC_PLUS(5));
	}
	else if (cursor->encoding == DDR || cursor->encoding == IDR)
	{
		jump = 7;
		location_info += get_half_c_int(CORE_PC_PLUS(2), vm);
		location_info += get_half_c_int(CORE_PC_PLUS(5), vm);
		reg_to_load = get_reg(cursor, CORE_PC_PLUS(6));
	}
	
	
	if (jump > 1 && info_to_load)
	{
		info_to_load = get_core_int(PC_PLUS(location_info % IDX_MOD), vm);
		*reg_to_load = info_to_load;
		if (*reg_to_load)
			cursor->carry = 1;
	}
	
	return (jump);
}