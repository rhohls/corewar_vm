/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 12:57:06 by rhohls           ###   ########.fr       */
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
**	we’ll use their contents as indexes.
*/


int	cw_sti(t_vm *vm, t_cursor *cursor)
{
	// int reg_num;
	char	*reg_info;
	int		dest;
	int 	jump;
	int		reg_info_as_int;
	char	 *register_info;
	
	dest = 0;
	jump = -1;
	reg_info = get_reg_info(cursor, vm->core[WRAP(cursor->pc + 2)]);
	
	if (EBYTE(cursor->encoding) == RRR)
	{
		//
		check below to see which is right
		//
		register_info = get_reg_info(cursor, CORE_PC_PLUS(3));
		dest += get_point_int(register_info);
		
		reg_info_as_int = get_point_int(get_reg_info(cursor, CORE_PC_PLUS(4)));
		dest += get_core_int(CORE_PC_PLUS(reg_info_as_int % IDX_MOD), vm);
		jump = 5;
	}
	else if (EBYTE(cursor->encoding) == RRD)
	{
		reg_info_as_int = get_point_int(get_reg_info(cursor, CORE_PC_PLUS(3)));
		dest += get_core_int(CORE_PC_PLUS(reg_info_as_int % IDX_MOD), vm);
		dest += get_half_m_int(CORE_PC_PLUS(4), vm);
		jump = 6;
	}
	else if (EBYTE(cursor->encoding) == RIR || EBYTE(cursor->encoding) == RDR)
	{
		dest += get_half_m_int(CORE_PC_PLUS(3), vm);	
		reg_info_as_int = get_point_int(get_reg_info(cursor, CORE_PC_PLUS(5)));
		dest += get_core_int(CORE_PC_PLUS(reg_info_as_int % IDX_MOD), vm);
		jump = 6;
				
	}
	else if (EBYTE(cursor->encoding) == RID || EBYTE(cursor->encoding) == RDD)
	{
		dest += get_half_m_int(CORE_PC_PLUS(3), vm);
		dest += get_half_m_int(CORE_PC_PLUS(5), vm);
		jump = 7;
	}
	
	if (jump > 0 && reg_info)
	{
		ft_memcpy(&CORE_PC_PLUS(dest % IDX_MOD), reg_info, REG_SIZE);
	}
	
	return (jump);
}