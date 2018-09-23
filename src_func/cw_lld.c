/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 10:50:31 by rhohls           ###   ########.fr       */
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

int	cw_lld(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	//printf("- in lld -\n");
=======
	// printf("- in lld -\n");
	int		info_to_load;
	int		location_info;
	int		*reg;
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	int 	jump;
	
	jump = cw_load(vm, cursor, 1);
	return (jump);
}