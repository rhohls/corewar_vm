/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:57:30 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 15:00:14 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			*get_reg(int relative_pc, t_vm *vm, t_cursor *cursor)
{
	int reg_num;

	reg_num = CORE_PC_PLUS(relative_pc) - 1;
	if (reg_check(cursor, reg_num))
		return (&(cursor->reg[reg_num]));
	else
		return (NULL);
}

int			*get_register(t_cursor *cursor, int reg_num)
{
	reg_num -= 1;
	if (reg_check(cursor, reg_num))
		return (&(cursor->reg[reg_num]));
	else
		return (NULL);
}

int			get_dir(int relative_pc, t_vm *vm, t_cursor *cursor, int half_size)
{
	if (half_size)
		return (get_half_c_int(PC_PLUS(relative_pc), vm));
	else
		return (get_core_int(PC_PLUS(relative_pc), vm));
}

int			get_ind(int relative_pc, t_vm *vm, t_cursor *cursor)
{
	int	indirect;

	indirect = get_half_c_int(PC_PLUS(relative_pc), vm) % IDX_MOD;
	return (get_half_c_int(PC_PLUS(indirect), vm));
}

int			get_ind_nomod(int relative_pc, t_vm *vm, t_cursor *cursor)
{
	int	indirect;

	indirect = get_half_c_int(PC_PLUS(relative_pc), vm);
	return (get_half_c_int(PC_PLUS(indirect), vm));
}
