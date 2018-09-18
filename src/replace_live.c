


#include "../includes/vm.h"

static int (*g_func_ptr2[17])(t_vm *vm, t_cursor *cursor) =
{// return int = amnt of jumps needed by pc ??/
	cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
	cw_lfork, cw_aff
};

static int (*jump_func_ptr[17])(char *program) =
{
	null_jump, live_jump, ld_jump, st_jump, add_jump, sub_jump, and_jump, or_jump,
	xor_jump, zjmp_jump, ldi_jump, sti_jump, fork_jump, lld_jump, lldi_jump,
	lfork_jump, aff_jump
};
/*
int    cw_st(char *program, int index)
{
    if program[index +1] == RRR //encoding byte
        return 3
    else if ...
        return 5;
}

while(1)
{
    if index > program_size
        break ;
    op_code = program[index]
    if op_code == 1
        replace;
    index += jump_function(op_code)
}


void	excute_live_instruction(t_cursor *cursor, t_vm *vm)
{
	int cursor_jump;
	
	cursor_jump = (*(g_func_ptr2[cursor->op_code]))(vm,cursor);	
	update_cursor_info(cursor, vm, cursor_jump);
	if (cursor->op_code == 1)
	{
		
	}
		cursor_jump = 0;
		
}

void	incr_live_cursor(t_vm *vm, t_list *players)
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
}*/

int		jump_function(int op_code, t_list *player, int index)
{
	int ret;
	t_player *temp;

	temp = ((t_player *)(player->content));
	ret = (*jump_func_ptr[op_code])(temp->program + index);
	return (ret);
}

void	replace_live(t_list *player, int index)
{
	int split[4];
	t_player *temp;

	temp = ((t_player *)(player->content));
	split[0] = (258 & 0x000000ff);
	split[1] = (258 & 0x0000ff00);
	split[2] = (258 & 0x00ff0000);
	split[3] = (258 & 0xff000000);
	
	temp->program[index + 1] = split[3];
	temp->program[index + 2] = split[2];
	temp->program[index + 3] = split[1];
	temp->program[index + 4] = split[0];
}

void	name_replacer(t_vm *vm, t_list *player)
{
	int		index;
	char	op_code;

	index = 0;
	printf("program_size = %d\n", ((t_player *)(player->content))->program_size);
	printf("program_size = %d\n", ((t_player *)(player->content))->program[index]);
	while (index < ((t_player *)(player->content))->program_size)
	{
		op_code = ((t_player *)(player->content))->program[index];
		if (op_code == 1)
			replace_live(player, index);
		index += jump_function(op_code, player, index);
	}
}