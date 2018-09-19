

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

int	cw_bitop(t_vm *vm, t_cursor *cursor, t_bitop *bitop)
{
	int		jump;
	
	bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(4));
	
	bitop->par1 = *(get_reg(cursor, CORE_PC_PLUS(4)));
	bitop->par1 = get_core_int(PC_PLUS(0), vm);
	bitop->par1 = get_half_c_int(PC_PLUS(0), vm);
	
	jump = 1;
	if (cursor->encoding == RRR)
	{
		bitop->par1 = *(get_reg(cursor, CORE_PC_PLUS(2)));
		bitop->par2 = *(get_reg(cursor, CORE_PC_PLUS(3)));
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(4));
		jump = 5;
	}
	else if (cursor->encoding == RIR)
	{
		bitop->par1 = *(get_reg(cursor, CORE_PC_PLUS(2)));
		bitop->par2 = get_half_c_int(PC_PLUS(3), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(5));
		jump = 6;
	}
	else if (cursor->encoding == IRR)
	{
		bitop->par1 = get_half_c_int(PC_PLUS(2), vm);
		bitop->par2 = *(get_reg(cursor, CORE_PC_PLUS(4)));
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(5));
		jump = 6;
	}
	else if (cursor->encoding == IIR)
	{
		bitop->par1 = get_half_c_int(PC_PLUS(2), vm);
		bitop->par2 = get_half_c_int(PC_PLUS(4), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(6));
		jump = 7;
	}
	else if (cursor->encoding == RDR)
	{
		bitop->par1 = *(get_reg(cursor, CORE_PC_PLUS(2)));
		bitop->par2 = get_core_int(PC_PLUS(3), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(7));
		jump = 8;
	}
	else if (cursor->encoding == DRR)
	{
		bitop->par1 = get_core_int(PC_PLUS(2), vm);
		bitop->par2 = *(get_reg(cursor, CORE_PC_PLUS(6)));
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(7));
		jump = 8;
	}
	else if (cursor->encoding == DDR)
	{
		bitop->par1 = get_core_int(PC_PLUS(2), vm);
		bitop->par2 = get_core_int(PC_PLUS(6), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(10));
		jump = 11;
	}	
	else if (cursor->encoding == DIR)
	{
		bitop->par1 = get_core_int(PC_PLUS(2), vm);
		bitop->par2 = get_half_c_int(PC_PLUS(6), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(8));
		jump = 9;
	}
	else if (cursor->encoding == IDR)	
	{
		bitop->par1 = get_half_c_int(PC_PLUS(2), vm);
		bitop->par2 = get_core_int(PC_PLUS(4), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(8));
		jump = 9;
	}
	return (jump);
}