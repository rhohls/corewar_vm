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
**			add & sub
**	par1, par2, par3
**	par1 = reg
**	par2 = reg
**	par3 = reg
**	This instruction takes 3 registers as parameter, adds the contents
**	of par1, par2 and stores the result in par 3. This operation
**	modifies the carry.
**
**		type:
**	add = 1
**	sub = 0
*/

static void	opperate(t_param *param, t_cursor *cursor, int type)
{
	if (param->success && param->reg_store != NULL)
	{
		if (type)
			*(param->reg_store) = param->par1 + param->par2;
		else
			*(param->reg_store) = param->par1 - param->par2;
		if (!(*(param->reg_store)))
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}

int	cw_math(t_vm *vm, t_cursor *cursor, t_param *param, int type)
{
	int		jump;
	int		*reg_info_1;
	int		*reg_info_2;
	int		*reg_store;

	jump = 1;
	param->success = 0;
	if ((cursor->encoding & RRR) == RRR)
	{
		jump = 5;
		if (!(reg_info_1 = get_reg(2, vm, cursor)))
			return (jump);
		if (!(reg_info_2 = get_reg(3, vm, cursor)))
			return (jump);
		reg_store = get_reg(4, vm, cursor);
		param->par1 = *reg_info_1;
		param->par2 = *reg_info_2;
		param->reg_store = reg_store;
		param->success = 1;
	}
	return (jump);
}
