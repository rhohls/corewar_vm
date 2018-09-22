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

int	cw_load(t_vm *vm, t_cursor *cursor, int long_ld)
{
	printf("- in ld -\n");
	int		info_to_load;
	int		location_info;
	int		*reg;
	int 	jump;

	jump = 1;
	if (cursor->encoding == DR)
	{
		info_to_load = get_dir(2, vm, cursor, 0);
		reg = get_reg(6, vm, cursor);
		jump = 7;
	}
	else if (cursor->encoding == IR)
	{
		location_info = get_ind(2, vm, cursor);		
		reg = get_reg(4, vm, cursor);
		jump = 5;
	}
	
	printf("cursor pc %d\n", cursor->pc);	
	printf("location for info %d (rel PC)-%d actual info: %d\n", location_info, location_info % IDX_MOD, info_to_load);
	
	if (jump > 1 && reg)
	{
		if (!long_ld)
			location_info = location_info % IDX_MOD;
		*reg = info_to_load;
		if (info_to_load)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	
	return (jump);
}
