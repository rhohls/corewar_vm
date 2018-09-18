


#include "../includes/vm.h"

static int (*g_func_ptr2[17])(t_vm *vm, t_cursor *cursor) =
{// return int = amnt of jumps needed by pc ??/
	cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
	cw_lfork, cw_aff
};


void	excute_live_instruction(t_cursor *cursor, t_vm *vm)
{
	int cursor_jump;
	
	cursor_jump = (*(g_func_ptr2[cursor->op_code]))(vm,cursor);	
	update_cursor_info(cursor, vm, cursor_jump);
	if (cursor->op_code == 1)
		// replace_info wiht player number
		cursor_jump = 0;
		
}

void	incr_live_cursor(t_vm *vm)
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
			excute_live_instruction(cursor, vm);
		}
		cursor_node = cursor_node->next;
	}
}

void	replace_live(t_vm *vm)
{
	incr_live_cursor(vm);
}


