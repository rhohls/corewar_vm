/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:55 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 09:51:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_cursor *create_cursor(t_vm *vm, int pc)
{
	t_cursor *cursor;
	int i;
	
	cursor = (t_cursor *)malloc(sizeof(t_cursor));
	cursor->pc = pc;
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_bzero(cursor->reg[i], REG_SIZE);
		i++;
	}
	update_cursor(cursor, vm, 0);
	
	return (cursor);
}

void	add_cursor_pc(t_vm *vm, int pc)
{
	t_list *node;
	node = ft_lstnew(0, 0);
	node->content = create_cursor(vm, 29);
	ft_stackpush(vm->cursor_stack, node);
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
		if (cursor->curr_cycle <= 0)
			excute_instruction(cursor, vm);
		cursor_node = cursor_node->next;
	}
}
