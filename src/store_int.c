

#include "../includes/vm.h"

void	store_core_int(int number, int core_dest_start, t_vm *vm)
{
	char *num;
	num = (char *)(&number);
	
	vm->core[WRAP(core_dest_start + 0)] = num[3];
	vm->core[WRAP(core_dest_start + 1)] = num[2];
	vm->core[WRAP(core_dest_start + 2)] = num[1];
	vm->core[WRAP(core_dest_start + 3)] = num[0];
}

void	replace_player_num(int player_number, int prog_index, char *program)
{
	char *num;
	num = (char *)(&player_number);
	
	program[prog_index + 0] = num[3];
	program[prog_index + 1] = num[2];
	program[prog_index + 2] = num[1];
	program[prog_index + 3] = num[0];
}