/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:32:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/13 11:56:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int (*g_func_ptr[17])(t_vm *vm, t_cursor *cursor) =
{// return int = amnt of jumps needed by pc ??/
	cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
	cw_lfork, cw_aff
};

void kill_cursor(t_cursor *cursor, t_vm *vm)
{
	// itererate through vm cursor list
	// remove cursor from list
}

int get_op_code(t_cursor *cursor, t_vm *vm)
{
	int op_code;
	
	op_code = vm->core[cursor->pc];
	
	return (op_code);
}

void update_cursor(t_cursor *cursor, t_vm *vm, int cursor_jump)
{
	// assign new opcode and cycle from PC
	cursor->pc = WRAP(cursor->pc + cursor_jump);
	cursor->op_code = get_op_code(cursor, vm);
	cursor->encoding = vm->core[WRAP(cursor->pc + 1)];
	if (cursor->op_code >= 16) // or more errors
		kill_cursor(cursor, vm);
	else
	{
		cursor->curr_cycle = (vm->op_table[cursor->op_code]).cycles;
	}
}

void	excute_instruction(t_cursor *cursor, t_vm *vm)
{
	int cursor_jump;
	
	cursor_jump = (*(g_func_ptr[cursor->op_code]))(vm,cursor);
	if (cursor_jump < 1)
		kill_cursor(cursor, vm);
	else
		update_cursor(cursor, vm, cursor_jump);
}

