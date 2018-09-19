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


int	cw_sti(t_vm *vm, t_cursor *cursor)
{
	// int reg_num;
	int		*reg_info_toload;
	int		dest;
	int 	jump;
	
	dest = 0;
	jump = 0 ;
	reg_info_toload = get_reg(cursor, vm->core[WRAP(cursor->pc + 2)]);
	
	if (cursor->encoding == RRR)
	{	
		dest += *(get_reg(cursor, CORE_PC_PLUS(3)));
		dest += *(get_reg(cursor, CORE_PC_PLUS(4)));
		jump = 5;
	}
	else if (cursor->encoding == RRD)
	{
		dest += *(get_reg(cursor, CORE_PC_PLUS(3)));
		dest += get_half_c_int(CORE_PC_PLUS(4), vm);
		jump = 6;
	}
	else if (cursor->encoding == RIR || cursor->encoding == RDR)
	{
		dest += get_half_c_int(CORE_PC_PLUS(3), vm);	
		dest += *(get_reg(cursor, CORE_PC_PLUS(5)));
		jump = 6;	
	}
	else if (cursor->encoding == RID || cursor->encoding == RDD)
	{
		dest += get_half_c_int(CORE_PC_PLUS(3), vm);
		dest += get_half_c_int(CORE_PC_PLUS(5), vm);
		jump = 7;
	}
	
	if (jump > 0 && reg_info_toload)
	{
		// marking sheet says idx mod here
		store_core_int(*reg_info_toload, PC_PLUS(dest %IDX_MOD), vm);
	}
	
	return (jump);
}