


#include "../includes/vm.h"

static int (*jump_func_ptr[17])(char *program) =
{
	null_jump, live_jump, ld_jump, st_jump, add_jump, sub_jump, and_jump, or_jump,
	xor_jump, zjmp_jump, ldi_jump, sti_jump, fork_jump, lld_jump, lldi_jump,
	lfork_jump, aff_jump
};

int		jump_function(int op_code, t_list *player, int index)
{
	int ret;
	t_player *temp;

	temp = ((t_player *)(player->content));
	ret = (*jump_func_ptr[op_code])(temp->program + index);
	return (ret);
}

void    replace_player_num(t_list *player, int prog_index)
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
	
	// also replace r1 with player number
	index = 0;
	temp = ((t_player *)(player->content));
<<<<<<< HEAD
	// //printf("program_size = %d\n", temp->program_size);
	// //printf("program_size = %d\n", temp->program[index]);
=======
	// // printf("program_size = %d\n", temp->program_size);
	// // printf("program_size = %d\n", temp->program[index]);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	while (index < temp->program_size)
	{
		op_code = temp->program[index];
		if (op_code == 1)
			replace_player_num(player, index);
		index += jump_function(op_code, player, index);
	}
}