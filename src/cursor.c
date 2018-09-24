/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:49:55 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 11:28:47 by rhohls           ###   ########.fr       */
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
		cursor->reg[i] = 0;
		i++;
	}
	update_cursor_info(cursor, vm, 0);
	return (cursor);
}

void	add_cursor_to_cursorlist(t_vm *vm, t_cursor *new_cursor)
{
	t_list *node;
	node = ft_lstnew(0, 0);
	node->content = new_cursor;
	ft_stackpush(vm->cursor_stack, node);
}

void	add_initial_player_cursor(t_vm *vm, int pc, t_player *player)
{
	t_list		*node;
	t_cursor	*cursor;
	node = ft_lstnew(0, 0);
	cursor = create_cursor(vm, pc);
	
	cursor->player_num = player->player_num;
	(cursor->reg)[0] = player->player_num;
	
	node->content = cursor;
	ft_stackpush(vm->cursor_stack, node);
}

void	update_cursor_info(t_cursor *cursor, t_vm *vm, int cursor_jump)
{
	// assign new opcode and cycle from PC
	// //printf("\n Updating cursor\n");
	
	// //printf("un wrap: old_pc-%d  jump-%d\t wrapped-%d\t",cursor->pc, cursor_jump, WRAP(cursor->pc + cursor_jump));
	// //printf("Memesize: %d\n", MEM_SIZE);
	
	// //printf("old pc %d - ", cursor->pc);
	n_print_cursor(vm, cursor->pc);
	cursor->pc = WRAP(cursor->pc + cursor_jump);
	// //printf("new pc %d \n", cursor->pc);	
	cursor->op_code = CORE_PC_PLUS(0);
	// //printf("core info = %02x\t", EBYTE(vm->core[WRAP(cursor->pc)]));
	// //printf("op_code = %02x\n", cursor->op_code);		
	cursor->encoding = CORE_PC_PLUS(1);
	if (cursor->op_code >= 16) // or more errors
		cursor->curr_cycle = 1;
	else
		cursor->curr_cycle = (vm->op_table[cursor->op_code]).cycles;
	// //printf("number of cycles: %d\n", cursor->curr_cycle);
}

void	incr_all_cursor(t_vm *vm, int *print)
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
			// //printf("updating cursor at %d\n", cursor->pc);
			excute_instruction(cursor, vm);
			*print = 1;
			// //printf("updated!\n");
		}
		cursor_node = cursor_node->next;
	}
}
