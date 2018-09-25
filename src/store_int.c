

#include "../includes/vm.h"

void	n_print_stored_int(int core_dest_start, t_vm *vm)
{
	int	i;
	int	x;
	int y;

	y = 1;
	i = 0;
	x = core_dest_start;
	// n_print_core(vm);
	while (x >= OCTET)
	{
		x -= OCTET;
		y++;
	}
	while (i < 4)
	{
		n_putnbr_hex(vm, (unsigned char)vm->core[core_dest_start + i], (x * 3) + i + 1, y, 4);
		if (i == 1)
			i++;
		i++;
	}
	
	n_refresh_all(vm);
}

void	store_core_int(int number, int core_dest_start, t_vm *vm)
{
	char *num;
	num = (char *)(&number);
	
	vm->core[WRAP(core_dest_start + 0)] = num[3];
	vm->core[WRAP(core_dest_start + 1)] = num[2];
	vm->core[WRAP(core_dest_start + 2)] = num[1];
	vm->core[WRAP(core_dest_start + 3)] = num[0];
	if (vm->cwv.mode)
		n_print_stored_int(core_dest_start, vm);
}
