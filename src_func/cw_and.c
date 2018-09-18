/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 10:37:08 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**			&
** and par1, par2, par3
** par1 = reg, ind, dir
** par1 = reg, ind, dir
** par3 = reg
** perform bit operation on par1 and par2
** stores the result in par3
** This operation modifies the carry
*/

int	cw_and(t_vm *vm, t_cursor *cursor)
{
	int		jump;
	char	*reg_store;
	
	reg_store = get_reg(cursor, CORE_PC_PLUS(4));	
	
	if (EBYTE(cursor->encoding) == RRR)
		jump = 5;
	else if (EBYTE(cursor->encoding) == IRR || EBYTE(cursor->encoding) == RIR)
		jump = 6;
	else if (EBYTE(cursor->encoding) == IIR)
		jump = 7;
	else if (EBYTE(cursor->encoding) == DRR || EBYTE(cursor->encoding) == RDR)
		jump = 8;
	else if (EBYTE(cursor->encoding) == DDR)
		jump = 11;
	else if (EBYTE(cursor->encoding) == DIR || EBYTE(cursor->encoding) == IDR)
		jump = 9;

		
	if (jump > 0)
	{
		if (reg_store != 0)
			cursor->carry = 1;
	}
	
	return (jump);
}