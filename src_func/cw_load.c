/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 09:50:51 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	ld par1, par2
**	par1 = dir or ind
**	par2 = reg
**	ld coppies REG_SIZE bytes from par1 (PC + (par1 % IDX_MOD))
**	into par2(reg)
*/

static void	load_it(int *reg, int info_to_load, t_cursor *cursor)
{
	*reg = info_to_load;
	if (info_to_load)
		cursor->carry = 0;
	else
		cursor->carry = 1;
}

int			cw_load(t_vm *vm, t_cursor *cursor, int long_ld)
{
	int		info_to_load;
	int		*reg;
	int		jump;

	jump = 1;
	if (cursor->encoding == DR)
	{
		info_to_load = get_dir(2, vm, cursor, 0);
		reg = get_reg(6, vm, cursor);
		jump = 7;
	}
	else if (cursor->encoding == IR)
	{
		if (long_ld)
			info_to_load = get_ind_nomod(2, vm, cursor);
		else
			info_to_load = get_ind(2, vm, cursor);
		reg = get_reg(4, vm, cursor);
		jump = 5;
	}
	if (jump > 1 && reg)
		load_it(reg, info_to_load, cursor);
	return (jump);
}
