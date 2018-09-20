/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 14:42:04 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	add par1, par2, par3
**	par1 = reg
**	par2 = reg
**	par3 = reg
**	This instruction takes 3 registers as parameter, adds the contents
**	of par1, par2 and stores the result in par 3. This operation
**	modifies the carry.
*/

int	cw_add(t_vm *vm, t_cursor *cursor)
{
	int		jump;
	int 	*reg_info_1;
	int		*reg_info_2;
	int		*reg_store;
	
	jump = 1;
	if ((cursor->encoding & RRR) == RRR)
	{
		jump = 5;
		if (!(reg_info_1 = get_reg(cursor, CORE_PC_PLUS(2))))
			return (jump);
		if (!(reg_info_2 = get_reg(cursor, CORE_PC_PLUS(3))))
			return (jump);	
		reg_store = get_reg(cursor, CORE_PC_PLUS(4));
		if (reg_store != NULL)
		{
			*reg_store = *reg_info_1 + *reg_info_2;
			cursor->carry = 1;
		}
	}
	return (jump);
}