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
<<<<<<< HEAD
	//printf("- in add -\n");
=======
	// printf("- in add -\n");
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	int		jump;
	t_param	param;
	
	jump = cw_math(vm, cursor, &param);
	
	if (param.success && param.reg_store != NULL)
	{
		*(param.reg_store) = param.par1 + param.par2;
		if (!(*(param.reg_store)))
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	return (jump);
}