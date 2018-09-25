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
	t_param	bitop;

	jump = cw_bitop(vm, cursor, &bitop);
	if (bitop.success && bitop.reg_store)
	{
		*(bitop.reg_store) = bitop.par1 & bitop.par2;
		if (*(bitop.reg_store) == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	return (jump);
}
