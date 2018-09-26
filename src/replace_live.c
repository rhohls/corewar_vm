


#include "../includes/vm.h"

static int (*g_jump_func_ptr[17])(char *program) =
{
	null_jump, live_jump, ld_jump, st_jump, add_jump, sub_jump, and_jump,
	or_jump, xor_jump, zjmp_jump, ldi_jump, sti_jump, fork_jump, lld_jump,
	lldi_jump, lfork_jump, aff_jump
};

int		jump_function(int op_code, t_list *player, int index)
{
	int ret;
	t_player *temp;

	temp = ((t_player *)(player->content));
	ret = (*g_jump_func_ptr[op_code])(temp->program + index);
	return (ret);
}

void	replace_player_num(t_list *player, int prog_index)
{
	char *num;
	t_player *temp;

	temp = ((t_player *)(player->content));
	num = (char *)(&temp->player_num);
	temp->program[prog_index + 1] = num[3];
	temp->program[prog_index + 2] = num[2];
	temp->program[prog_index + 3] = num[1];
	temp->program[prog_index + 4] = num[0];
}

void	name_replacer(t_vm *vm, t_list *player)
{
	int			index;
	t_player	*temp;
	char		op_code;

	index = 0;
	temp = ((t_player *)(player->content));
	while (index < temp->program_size)
	{
		op_code = temp->program[index];
		if (op_code == 1)
			replace_player_num(player, index);
		index += jump_function(op_code, player, index);
	}
}
