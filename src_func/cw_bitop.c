/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_bitop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:18:03 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/25 16:18:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**			...
** and par1, par2, par3
** par1 = reg, ind, dir
** par1 = reg, ind, dir
** par3 = reg
** perform bit operation on par1 and par2
** stores the result in par3
** This operation modifies the carry
**
** Universal for < or xor and >
*/

int	cw_bitop(t_vm *vm, t_cursor *cursor, t_param *bitop)
{
	int		jump;
	int		*reg;
	t_ldi	bit;

	bit.jump = 1;
	if (bit1(vm, cursor, bitop, &bit) == 1)
		bitop->success = 1;
	else
		bitop->success = 0;
	return (bit.jump);
}
