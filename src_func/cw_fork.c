/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 15:12:30 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	cw_fork(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*new_cursor;
	int			new_pc;
	int			i;
	
	new_pc = get_half_c_int(PC_PLUS(1), vm);
	new_cursor = create_cursor(vm, new_pc);
	
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_memcpy(new_cursor->reg[i], cursor->reg[i], REG_SIZE);
		i++;
	}
	
	add_cursor_to_cursorlist(vm, new_cursor);	
	return (1);
}