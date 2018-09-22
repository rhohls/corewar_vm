/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 06:58:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	fork par1
**	create new cursor, inherates state
**	loads cursor at par1
*/

static t_cursor *duplicate_cursor(t_vm *vm, t_cursor *cursor, int new_pc)
{
	t_cursor	*new_cursor;
	int			i;
	
	new_cursor = create_cursor(vm, new_pc);
	new_cursor->player_num = cursor->player_num;
	new_cursor->carry = cursor->carry;

	i = 0;
	while (i < REG_NUMBER)
	{
		new_cursor->reg[i] = cursor->reg[i];
		i++;
	}
	return (new_cursor);
}

int	cw_fork(t_vm *vm, t_cursor *cursor)
{
	printf("- in fork -\n");
	t_cursor	*new_cursor;
	int			new_pc;
	
	new_pc = get_half_c_int(PC_PLUS(1), vm) % IDX_MOD;
	new_pc = PC_PLUS(new_pc);
	new_cursor = duplicate_cursor(vm, cursor, new_pc);	
	add_cursor_to_cursorlist(vm, new_cursor);	
	printf("new pc location: %d with mod rel to pc: %d\n", get_half_c_int(PC_PLUS(1), vm), new_pc);
	return (3);
}