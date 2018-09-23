/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 09:50:51 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	ld par1, par2
**	par1 = dir or ind
**	par2 = reg
**	ld coppies REG_SIZE bytes from par1 (PC + (par1 % IDX_MOD)) 
**	into par2(reg)
*/

int	cw_ld(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	//printf("- in ld -\n");
	int 	jump;
=======
	// printf("- in ld -\n");
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
	info_to_load = get_core_int(PC_PLUS(location_info % IDX_MOD), vm);
	
	// printf("cursor pc %d\n", cursor->pc);	
	// printf("location for info %d (rel PC)-%d actual info: %d\n", location_info, location_info % IDX_MOD, info_to_load);
	
	if (jump > 1 && info_to_load)
	{
		*reg = info_to_load;
		if (*reg)
			cursor->carry = 1;
	}
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	
	jump = cw_load(vm, cursor, 0);

	return (jump);
}
