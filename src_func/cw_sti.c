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
	// printf("- in sti -\n");
	
	// int reg_num;
	int		*reg;
	int		*reg_info_toload;
	int		dest;
	int 	jump;
	
	dest = 0;
	jump = 1;
	reg_info_toload = get_reg(cursor, CORE_PC_PLUS(2));
	
	
	// printf("cursor pc %d\n", cursor->pc);
	// printf("register num for info %d  -  val: %d\n", CORE_PC_PLUS(2), *reg_info_toload);
	
	
	
	
	if (cursor->encoding == RRR)
	{	
		jump = 5;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(3))))
			return (jump);
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(3), *reg);
		dest += *(reg);
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(4))))
			return (jump);
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(4), *reg);
		dest += *(reg);
	}
	else if (cursor->encoding == RRD)
	{
		jump = 6;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(3))))
			return (jump);
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(3), *reg);
		dest += *(reg);
		dest += get_half_c_int(PC_PLUS(4), vm);
	}
	else if (cursor->encoding == RIR || cursor->encoding == RDR)
	{
		jump = 6;
		dest += get_half_c_int(PC_PLUS(3), vm);	
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(5))))
			return (jump);
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(5), *reg);
		dest += *(reg);
	}
	else if (cursor->encoding == RID || cursor->encoding == RDD)
	{
		jump = 7;
		dest += get_half_c_int(PC_PLUS(3), vm);
		dest += get_half_c_int(PC_PLUS(5), vm);
	}
	
	if (jump > 0 && reg_info_toload)
	{
		// marking sheet says idx mod here
		store_core_int(*reg_info_toload, PC_PLUS(dest %IDX_MOD), vm);
	}
	// printf("relative to pc where to stor info %d with mod %d\n", dest, dest%IDX_MOD);
	
	print_board_location((const unsigned char *)(&(vm->core[0])), MEM_SIZE);
	return (jump);
}