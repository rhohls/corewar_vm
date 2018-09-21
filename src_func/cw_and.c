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
	printf("- in and -\n");
	int		jump;
	t_bitop	bitop;
	jump = cw_bitop(vm, cursor, &bitop);
	
	printf("123\n");
	printf("-- succ? %d\n",bitop.success);
	if (bitop.success)
	{
		printf("reg_store address %p \n", bitop.reg_store);
		printf("par1: %d\n", bitop.par1);
		printf("par2: %d\n", bitop.par2);
		*(bitop.reg_store) = bitop.par1 & bitop.par2;
		if (*(bitop.reg_store) == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;			
	}
	printf("4423\n");

	return (jump);
}