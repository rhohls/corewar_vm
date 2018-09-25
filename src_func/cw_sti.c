/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 11:44:23 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	sti par1,par2,par3
**	par1 = reg
**	par2 = dir or ind or reg
**	par3 = dir or reg
**	sti copies REG_SIZE bytes of par1 at address (par2 + par3)
**	Parameters 2 and 3 are indexes. If they are registers,
**	their contents are used as indexes.
*/

int	cw_sti(t_vm *vm, t_cursor *cursor)
{
	int		*reg;
	int		*reg_info_toload;
	int		dest;
	int		jump;

	dest = 0;
	jump = 1;
	reg_info_toload = get_reg(2, vm, cursor);
	if (cursor->encoding == RRR)
	{
		jump = 5;
		if (!(reg = get_reg(3, vm, cursor)))
			return (jump);
		dest += *(reg);
		if (!(reg = get_reg(4, vm, cursor)))
			return (jump);
		dest += *(reg);
	}
	else if (cursor->encoding == RRD)
	{
		jump = 6;
		if (!(reg = get_reg(3, vm, cursor)))
			return (jump);
		dest += *(reg);
		dest += get_dir(4, vm, cursor, 1);
	}
	else if (cursor->encoding == RIR)
	{
		jump = 6;
		dest += get_ind(3, vm, cursor);
		if (!(reg = get_reg(5, vm, cursor)))
			return (jump);
		dest += *(reg);
	}
	else if (cursor->encoding == RDR)
	{
		jump = 6;
		dest += get_dir(3, vm, cursor, 1);
		if (!(reg = get_reg(5, vm, cursor)))
			return (jump);
		dest += *(reg);
	}
	else if (cursor->encoding == RID)
	{
		jump = 7;
		dest += get_ind(3, vm, cursor);
		dest += get_dir(5, vm, cursor, 1);
	}
	else if (cursor->encoding == RDD)
	{
		jump = 7;
		dest += get_dir(3, vm, cursor, 1);
		dest += get_ind(5, vm, cursor);
	}
	if (jump > 0 && reg_info_toload)
	{
		store_core_int(*reg_info_toload, PC_PLUS(dest % IDX_MOD),
							vm, cursor->player_num);
	}
	return (jump);
}
