/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 07:19:33 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
/*
**	add par1, par2, par3
**	par = reg
**	This instruction takes 3 registers as parameter, adds the contents
**	of par1, par2 and stores the result in par 3. This operation
**	modifies the carry.
*/

int	cw_add(t_vm *vm, t_cursor *cursor)
{
	int		jump;
	int 	reg_info_1;
	int		reg_info_2;
	char	*reg_store;
	
	jump = 0;
	
	if ((cursor->encoding & RRR) == RRR)
	{
		reg_info_1 = get_point_int(get_reg(cursor, CORE_PC_PLUS(2)));
		reg_info_2 = get_point_int(get_reg(cursor, CORE_PC_PLUS(3)));
		reg_store = get_reg(cursor, CORE_PC_PLUS(4));
		
		// change reg to int instead of char?
		if (reg_store != 0)
			cursor->carry = 1;
		jump = 5;
	}
	return (jump);
}