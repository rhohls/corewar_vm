/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 10:50:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/vm.h"

/*
**	sub par1, par2, par3
**	par1 = reg
**	par2 = reg
**	par3 = reg
**	This instruction takes 3 registers as parameter, subtracts the contents
**	of par1, par2 and stores the result in par 3. This operation
**	modifies the carry.
*/

int	cw_sub(t_vm *vm, t_cursor *cursor)
{
	int		jump;
	int 	reg_info_1;
	int		reg_info_2;
	int		*reg_store;
	
	jump = 1;
	if ((cursor->encoding & RRR) == RRR)
	{
		
		reg_info_1 = *(get_reg(cursor, CORE_PC_PLUS(2)));
		reg_info_2 = *(get_reg(cursor, CORE_PC_PLUS(3)));
		reg_store = get_reg(cursor, CORE_PC_PLUS(4));
		
		if (reg_store != NULL)
		{
			*reg_store = reg_info_1 - reg_info_2;
			cursor->carry = 1;
			jump = 5;
		}
	}
	return (jump);
}