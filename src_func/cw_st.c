/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 16:32:48 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	st par1, par2
**	par1 = dir or ind
**	par2 = reg
**	st coppies REG_SIZE bytes from par2 (reg) into 
**	par1 (PC + (par1 % IDX_MOD)) 
*/

int	cw_st(t_vm *vm, t_cursor *cursor)
{

	// int reg_num;
	int		*reg;
	int		*reg_info;
	int		dest;
	int 	jump;


	jump = 1;
	reg_info = get_reg(cursor, CORE_PC_PLUS(2));
	
	if (cursor->encoding == RR)
	{
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(3))))
			return (jump);
		dest = *(reg);
		jump = 4;
	}
	else if (cursor->encoding == RI)
	{
		dest = get_half_c_int(PC_PLUS(3), vm);
		jump = 5;
	}
	if (jump > 1 && reg_info)
	{
		store_core_int(*reg_info, PC_PLUS(dest %IDX_MOD), vm);
	}
	return (jump);
}