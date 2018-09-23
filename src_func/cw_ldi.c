/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 10:50:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	ldi par1, par2, par3
**	par1 = dir or ind or reg_to_load
**	par2 = reg_to_load or dir
**	par3 = reg_to_load
**
**	takes values at par1, and par2
**	add together to find location of info
**	store info at location into par 3
**	This operation modifies the carry.
*/

int	cw_ldi(t_vm *vm, t_cursor *cursor)
{
	//printf("- in ldi -\n");
	int 	jump;

	jump = cw_load_i(vm, cursor, 0);
	return (jump);
}