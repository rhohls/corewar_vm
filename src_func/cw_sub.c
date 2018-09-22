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
	// printf("- in sub -\n");
	int		jump;
	t_bitop	bitop;
	
	jump = cw_math(vm, cursor, &bitop);
	
	if (bitop.success && bitop.reg_store != NULL)
	{
		*(bitop.reg_store) = bitop.par1 + bitop.par2;
		if (!(*(bitop.reg_store)))
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	return (jump);
}