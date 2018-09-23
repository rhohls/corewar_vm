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
<<<<<<< HEAD
	//printf("- in sti -\n");
=======
	// printf("- in sti -\n");
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	
	// int reg_num;
	int		*reg;
	int		*reg_info_toload;
	int		dest;
	int 	jump;
	
	dest = 0;
	jump = 1;
	reg_info_toload = get_reg(2, vm, cursor);
	
	
<<<<<<< HEAD
	//printf("cursor pc %d\n", cursor->pc);
	//printf("register num for info %d  -  val: %d\n", CORE_PC_PLUS(2), *reg_info_toload);
=======
	// printf("cursor pc %d\n", cursor->pc);
	// printf("register num for info %d  -  val: %d\n", CORE_PC_PLUS(2), *reg_info_toload);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	
	
	
	
	if (cursor->encoding == RRR)
	{	
		jump = 5;
		if (!(reg = get_reg(3, vm, cursor)))
			return (jump);
<<<<<<< HEAD
		// //printf("register num %d  -  val: %d\n", CORE_PC_PLUS(3), *reg);
=======
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(3), *reg);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
		dest += *(reg);
		if (!(reg = get_reg(4, vm, cursor)))
			return (jump);
<<<<<<< HEAD
		// //printf("register num %d  -  val: %d\n", CORE_PC_PLUS(4), *reg);
=======
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(4), *reg);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
		dest += *(reg);
	}
	else if (cursor->encoding == RRD)
	{
		jump = 6;
		if (!(reg = get_reg(3, vm, cursor)))
			return (jump);
<<<<<<< HEAD
		// //printf("register num %d  -  val: %d\n", CORE_PC_PLUS(3), *reg);
=======
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(3), *reg);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
		dest += *(reg);
		dest += get_dir(4, vm, cursor, 1);
	}
	else if (cursor->encoding == RIR)
	{
		jump = 6;
		dest += get_ind(3, vm, cursor);	
		if (!(reg = get_reg(5, vm, cursor)))
			return (jump);
<<<<<<< HEAD
		// //printf("register num %d  -  val: %d\n", CORE_PC_PLUS(5), *reg);
=======
		// printf("register num %d  -  val: %d\n", CORE_PC_PLUS(5), *reg);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
		dest += *(reg);
	}
	else if (cursor->encoding == RDR)
	{
		jump = 6;
		dest += get_dir(3, vm, cursor, 1);		
		if (!(reg = get_reg(5, vm, cursor)))
			return (jump);
		// //printf("register num %d  -  val: %d\n", CORE_PC_PLUS(5), *reg);
		dest += *(reg);
	}
	else if (cursor->encoding == RID)
	{
		jump = 7;
		dest += get_ind(3, vm, cursor);	
		dest += get_dir(5, vm, cursor, 1);
	}
	else if (cursor->encoding == RDD)
	{
		jump = 7;
		dest += get_dir(3, vm, cursor, 1);
		dest += get_ind(5, vm, cursor);	
	}
	
	if (jump > 0 && reg_info_toload)
	{
		// marking sheet says idx mod here
		store_core_int(*reg_info_toload, PC_PLUS(dest %IDX_MOD), vm);
	}
<<<<<<< HEAD
	// //printf("relative to pc where to stor info %d with mod %d\n", dest, dest%IDX_MOD);
=======
	// printf("relative to pc where to stor info %d with mod %d\n", dest, dest%IDX_MOD);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	
	// print_board_location((const unsigned char *)(&(vm->core[0])), MEM_SIZE);
	return (jump);
}