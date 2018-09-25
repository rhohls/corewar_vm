

#include "../includes/vm.h"

/*
**			...
** and par1, par2, par3
** par1 = reg, ind, dir
** par1 = reg, ind, dir
** par3 = reg
** perform bit operation on par1 and par2
** stores the result in par3
** This operation modifies the carry
**
** Universal for - or xor and -
*/

int	cw_bitop(t_vm *vm, t_cursor *cursor, t_param *bitop)
{
	//printf("- in bitop -\n");
	int		jump;
	int		info_location;
	int		indirect;
	int		*reg;

	jump = 1;
	bitop->success = 0;
	if (cursor->encoding == RRR)
	{
		jump = 5;
		if (!(reg = get_reg(2, vm, cursor)))
			return (jump);
		bitop->par1 = *(reg);
		if (!(reg = get_reg(3, vm, cursor)))
			return (jump);
		bitop->par2 = *(reg);
		bitop->reg_store = get_reg(4, vm, cursor);
	}
	else if (cursor->encoding == RIR)
	{
		jump = 6;
		if (!(reg = get_reg(2, vm, cursor)))
			return (jump);
		bitop->par1 = *(reg);
		bitop->par2 = get_ind(3, vm, cursor);
		bitop->reg_store = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == IRR)
	{
		jump = 6;
		bitop->par1 = get_ind(2, vm, cursor);
		if (!(reg = get_reg(4, vm, cursor)))
			return (jump);
		bitop->par2 = *(reg);
		bitop->reg_store = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == IIR)
	{
		jump = 7;
		bitop->par1 = get_ind(2, vm, cursor);
		bitop->par2 = get_ind(4, vm, cursor);
		bitop->reg_store = get_reg(6, vm, cursor);
	}
	else if (cursor->encoding == RDR)
	{
		jump = 8;
		if (!(reg = get_reg(2, vm, cursor)))
			return (jump);
		bitop->par1 = *(reg);
		bitop->par2 = get_dir(3, vm, cursor, 0);
		bitop->reg_store = get_reg(7, vm, cursor);
	}
	else if (cursor->encoding == DRR)
	{
		jump = 8;
		bitop->par1 = get_dir(2, vm, cursor, 0);
		if (!(reg = get_reg(6, vm, cursor)))
			return (jump);
		bitop->par2 = *(reg);
		bitop->reg_store = get_reg(7, vm, cursor);
	}
	else if (cursor->encoding == DDR)
	{
		jump = 11;
		bitop->par1 = get_dir(2, vm, cursor, 0);
		bitop->par2 = get_dir(6, vm, cursor, 0);
		bitop->reg_store = get_reg(10, vm, cursor);	
	}	
	else if (cursor->encoding == DIR)
	{
		jump = 9;
		bitop->par1 = get_dir(2, vm, cursor, 0);
		bitop->par2 = get_ind(6, vm, cursor);
		bitop->reg_store = get_reg(8, vm, cursor);
	}
	else if (cursor->encoding == IDR)	
	{
		jump = 9;
		bitop->par1 = get_ind(2, vm, cursor);
		bitop->par2 = get_dir(4, vm, cursor, 0);
		bitop->reg_store = get_reg(8, vm, cursor);
	}
	else
		return (jump);
	// printf("bitop->par1 : %d\n",bitop->par1);
	// printf("bitop->par2 : %d\n",bitop->par2);
	bitop->success = 1;
	return (jump);
}