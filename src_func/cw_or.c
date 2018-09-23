/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 07:39:05 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**			|
** or par1, par2, par3
** par1 = reg, ind, dir
** par1 = reg, ind, dir
** par3 = reg
** perform bit operation on par1 and par2
** stores the result in par3
** This operation modifies the carry
*/

int	cw_or(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	//printf("- in or -\n");
=======
	// printf("- in or -\n");
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	int		jump;
	t_param	param;
	
	jump = cw_bitop(vm, cursor, &param);

	if (param.success && param.reg_store)
	{
		*(param.reg_store) = param.par1 | param.par2;
		if (*(param.reg_store) == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;	
	}
	return (jump);
}