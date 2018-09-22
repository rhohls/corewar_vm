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
	// printf("- in add -\n");
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