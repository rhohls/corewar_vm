/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/12 14:31:47 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	cw_sti(t_vm *vm, t_cursor *cursor)
{
	int reg;
	char *reg_bytes;
	int	dest;
	
	dest = 0;
	reg = vm->mem_board[cursor->pc + 2];
	reg_bytes = cursor->reg[reg];
	if (BYTE(cursor->encoding) == RRR)
	{
		dest += get_int(get_reg_info(cursor, vm->mem_board[cursor->pc + 3])); //get info at reg
		dest += get_int(get_reg_info(cursor, vm->mem_board[cursor->pc + 4]));
	}
	else if (BYTE(cursor->encoding) == RRD)
	{
		dest += get_int(get_reg_info(cursor, vm->mem_board[cursor->pc + 3]));
		dest += get_half_int(&vm->mem_board[cursor->pc + 4]);		
	}
	else if (BYTE(cursor->encoding) == RIR || BYTE(cursor->encoding) == RDR)
	{
		dest += get_half_int(&vm->mem_board[cursor->pc + 3]);		
		dest += get_int(get_reg_info(cursor, vm->mem_board[cursor->pc + 5]));
				
	}
	else if (BYTE(cursor->encoding) == RID || BYTE(cursor->encoding) == RDD)
	{
		
	}
	ft_memcpy();
}