/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:55 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/07 06:50:29 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_cursor *init_cursor(t_player player, int pc)
{
	t_cursor *cursor;
	
	cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	cursor->pc = pc;
	
	return (cursor);
}

void excute_instruction(t_cursor *cursor, t_vm *vm)
{
		
}

void	incr_cursor(t_vm *vm)
{
	t_list		*cursor_node;
	t_cursor	*cursor;
		
	cursor_node = vm->cursor_stack->start;
	while (cursor_node)
	{
		cursor = cursor_node->content;
		cursor->curr_cycle--;
		if (cursor->curr_cycle < 1)
			excute_instruction(cursor, vm);
		cursor_node = cursor_node->next;
	}
}

void	vm_loop(t_vm *vm)
{
	while(1)
	{
		incr_cursor(vm);
		
	}
}
