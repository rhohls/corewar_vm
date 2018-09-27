/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:32:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 14:39:44 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int (*g_func_ptr[17])(t_vm *vm, t_cursor *cursor) =
{
	cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
	cw_lfork, cw_aff
};

int		verify_cursor(t_cursor *cursor, t_vm *vm)
{
	if (cursor->op_code == CORE_PC_PLUS(0) &&
		cursor->op_code >= 0 && cursor->op_code < 17
		&& cursor->encoding == CORE_PC_PLUS(1))
		return (1);
	else
		return (0);
}

void	excute_instruction(t_cursor *cursor, t_vm *vm)
{
	int cursor_jump;
	int	colour;
	int y;
	int x;
	int x_y[2];

	y = cursor->pc / 64;
	x = cursor->pc % 64;
	if (vm->flags.visual && vm->cwv.mode)
	{
		colour = get_colour(vm, cursor->pc);
		x_y[0] = (x * 3) + 1;
		x_y[1] = y + 1;
		n_putnbr_hex(vm, CORE_PC_PLUS(0), x_y, colour);
	}
	if (verify_cursor(cursor, vm))
		cursor_jump = (*(g_func_ptr[cursor->op_code]))(vm, cursor);
	else
		cursor_jump = 1;
	update_cursor_info(cursor, vm, cursor_jump);
	if (vm->flags.visual && vm->cwv.mode)
	{
		n_print_one_cursor(vm, cursor);
		n_refresh_all(vm);
	}
}
