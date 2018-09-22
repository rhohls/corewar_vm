/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 10:50:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#include "../includes/vm.h"

/*
**	ld par1, par2
**	par1 = dir or ind
**	par2 = reg
**	ld coppies REG_SIZE bytes from par1 (PC + (par1 % IDX_MOD)) 
**	into par2(reg)
*/

int	cw_lld(t_vm *vm, t_cursor *cursor)
{
	// printf("- in lld -\n");
	int		info_to_load;
	int		location_info;
	int		*reg;
	int 	jump;

	jump = 1;
	if (cursor->encoding == DR)
	{
		location_info = get_core_int(PC_PLUS(2), vm);
		reg = get_reg(cursor, CORE_PC_PLUS(6));
		jump = 7;
	}
	else if (cursor->encoding == IR)
	{
		location_info = get_half_c_int(PC_PLUS(2), vm);
		reg = get_reg(cursor, CORE_PC_PLUS(4));
		jump = 5;
	}
	info_to_load = get_core_int(PC_PLUS(location_info), vm);
	
	if (jump > 1 && info_to_load)
	{
		*reg = info_to_load;
		if (*reg)
			cursor->carry = 1;
	}
	
	return (jump);
}