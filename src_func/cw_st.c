/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 13:46:51 by rhohls           ###   ########.fr       */
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
	int		info_to_load;
	int		loca_info;
	char	*reg;
	int 	jump;

	jump = -1;
	if (EBYTE(cursor->encoding) == RR)
	{
		loca_info = get_core_int(PC_PLUS(2), vm);
		reg = get_reg(cursor, CORE_PC_PLUS(6));
		jump = 7;
	}
	else if (EBYTE(cursor->encoding) == RI)
	{
		loca_info = get_half_c_int(PC_PLUS(2), vm);
		reg = get_reg(cursor, CORE_PC_PLUS(4));
		jump = 5;
	}
	info_to_load = get_core_int(PC_PLUS(loca_info % IDX_MOD), vm);
	
	if (jump > 0 && info_to_load)
	{
		ft_memcpy(reg, &info_to_load, REG_SIZE);
		cursor->carry = 1;
	}
	
	return (jump);
}