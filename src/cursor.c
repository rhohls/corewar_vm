/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:55 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 09:43:04 by rhohls           ###   ########.fr       */
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

void	add_cursor_to_cursorlist(t_vm *vm, t_cursor *new_cursor)
{
	t_list *node;
	node = ft_lstnew(0, 0);
	node->content = new_cursor;
	ft_stackpush(vm->cursor_stack, node);
}

void	add_cursor_to_vm(t_vm *vm, int pc)
{
	t_list *node;
	node = ft_lstnew(0, 0);
	node->content = create_cursor(vm, pc);
	ft_stackpush(vm->cursor_stack, node);
}


void	kill_cursor(t_cursor *cursor, t_vm *vm)
{
	// itererate through vm cursor list
	// remove cursor from list
}

void	update_cursor(t_cursor *cursor, t_vm *vm, int cursor_jump)
{
	// assign new opcode and cycle from PC
	// printf("old pc %d - ", cursor->pc);
	cursor->pc = WRAP(cursor->pc + cursor_jump);
	// printf("new pc %d \n", cursor->pc);	
	cursor->op_code = CORE_PC_PLUS(0);
	// printf("core info = %02x\t", vm->core[WRAP(cursor->pc)]);
	// printf("op_code = %02x\n", cursor->op_code);		
	cursor->encoding = CORE_PC_PLUS(1);
	if (cursor->op_code >= 16) // or more errors
		kill_cursor(cursor, vm);
	else
	{
		cursor->curr_cycle = (vm->op_table[cursor->op_code]).cycles;
	}
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
		{
			printf("updating cursor at %d\n", cursor->pc);
			excute_instruction(cursor, vm);
		}
		cursor_node = cursor_node->next;
	}
}
