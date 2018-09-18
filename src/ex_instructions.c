/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:32:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 10:47:23 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int (*g_func_ptr[17])(t_vm *vm, t_cursor *cursor) =
{// return int = amnt of jumps needed by pc ??/
	cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
	cw_lfork, cw_aff
};

int get_op_code(t_cursor *cursor, t_vm *vm)
{
	int op_code;
	
	op_code = CORE_PC_PLUS(0);
	return (op_code);
}


void	excute_instruction(t_cursor *cursor, t_vm *vm)
{
	int cursor_jump;
	
	cursor_jump = (*(g_func_ptr[cursor->op_code]))(vm,cursor);
	// if (cursor_jump < 1)
	// 	kill_cursor(cursor, vm);
	// else
	update_cursor_info(cursor, vm, cursor_jump);
}

