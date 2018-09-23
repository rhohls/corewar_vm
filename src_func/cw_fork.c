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

int	cw_fork(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	//printf("- in fork -\n");
	int		jump;
	
	jump = cw_forking(vm, cursor, 0);
	return (jump);
=======
	// printf("- in fork -\n");
	t_cursor	*new_cursor;
	int			new_pc;
	int			i;
	
	new_pc = get_half_c_int(PC_PLUS(1), vm) % IDX_MOD;
	new_cursor = create_cursor(vm, WRAP(new_pc));
	
	// printf("new pc location: %d wiht mod: %d\n", get_half_c_int(PC_PLUS(1), vm), new_pc);
	
	i = 0;
	while (i < REG_NUMBER)
	{
		new_cursor->reg[i] = cursor->reg[i];
		i++;
	}
	add_cursor_to_cursorlist(vm, new_cursor);	
	return (3);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
}