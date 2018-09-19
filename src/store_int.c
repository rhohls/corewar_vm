

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
