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
	//printf("- in and -\n");
	int		jump;
	t_param	param;
	jump = cw_bitop(vm, cursor, &param);
	
	// //printf("123\n");
	// //printf("-- succ? %d\n",param.success);
	if (param.success && param.reg_store)
	{
		// //printf("reg_store address %p \n", param.reg_store);
		// //printf("par1: %d\n", param.par1);
		// //printf("par2: %d\n", param.par2);
		*(param.reg_store) = param.par1 & param.par2;
		if (*(param.reg_store) == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;			
	}
	// //printf("4423\n");

	return (jump);
}