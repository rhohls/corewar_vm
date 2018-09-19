/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 14:49:19 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	ld par1, par2
**	par1 = dir or ind
**	par2 = reg
**	ld coppies REG_SIZE bytes from par1 (PC + (par1 % IDX_MOD)) 
**	into par2
**	
**	ld enc dir reg	
**	0	1	2	6
*/

int	cw_st(t_vm *vm, t_cursor *cursor)
{
	
	
	
	
	
	// int reg_num;
	char	*reg_info;
	char	*reg_dest;
	int		dest;
	int 	jump;


	jump = 0;
	reg_info = get_reg(cursor, CORE_PC_PLUS(2));
	
	if (cursor->encoding == RR)
	{
		reg_dest = get_reg(cursor, CORE_PC_PLUS(3));
		ft_memcpy(reg_dest, reg_info, REG_SIZE);
		jump = 4;
	}
	else if (cursor->encoding == RI)
	{
		dest = get_half_c_int(PC_PLUS(3), vm) % IDX_MOD;
		cw_reg_cpy(dest, reg_info, REG_SIZE, vm);
		jump = 4;
	}

	return (jump);
}