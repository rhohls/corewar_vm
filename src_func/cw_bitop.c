

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
	printf("- in bitop -\n");
	int		jump;
	int		info_location;
	int		indirect;
	int		*reg;
	
	jump = 1;
	bitop->success = 0;
	if (cursor->encoding == RRR)
	{
		jump = 5;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(2))))
			return (jump);
		bitop->par1 = *(reg);
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(3))))
			return (jump);
		bitop->par2 = *(reg);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(4));
	}
	else if (cursor->encoding == RIR)
	{
		jump = 6;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(2))))
			return (jump);
		bitop->par1 = *(reg);
		indirect = get_half_c_int(CORE_PC_PLUS(3), vm) % IDX_MOD;		
		bitop->par2 = get_half_c_int(PC_PLUS(indirect), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(5));
		
	}
	else if (cursor->encoding == IRR)
	{
		jump = 6;
		indirect = get_half_c_int(CORE_PC_PLUS(2), vm) % IDX_MOD;		
		bitop->par1 = get_half_c_int(PC_PLUS(indirect), vm);
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(4))))
			return (jump);
		bitop->par2 = *(reg);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(5));
	}
	else if (cursor->encoding == IIR)
	{
		jump = 7;
		indirect = get_half_c_int(CORE_PC_PLUS(2), vm) % IDX_MOD;		
		bitop->par1 = get_half_c_int(PC_PLUS(indirect), vm);
		indirect = get_half_c_int(CORE_PC_PLUS(4), vm) % IDX_MOD;		
		bitop->par2 = get_half_c_int(PC_PLUS(indirect), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(6));
	}
	else if (cursor->encoding == RDR)
	{
		jump = 8;
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(2))))
			return (jump);
		bitop->par1 = *(reg);
		bitop->par2 = get_core_int(PC_PLUS(3), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(7));
	}
	else if (cursor->encoding == DRR)
	{
		jump = 8;
		bitop->par1 = get_core_int(PC_PLUS(2), vm);
		if (!(reg = get_reg(cursor, CORE_PC_PLUS(6))))
			return (jump);
		bitop->par2 = *(reg);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(7));
	}
	else if (cursor->encoding == DDR)
	{
		jump = 11;
		bitop->par1 = get_core_int(PC_PLUS(2), vm);
		bitop->par2 = get_core_int(PC_PLUS(6), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(10));	
	}	
	else if (cursor->encoding == DIR)
	{
		jump = 9;
		bitop->par1 = get_core_int(PC_PLUS(2), vm);
		indirect = get_half_c_int(CORE_PC_PLUS(6), vm) % IDX_MOD;		
		bitop->par2 = get_half_c_int(PC_PLUS(indirect), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(8));
	}
	else if (cursor->encoding == IDR)	
	{
		jump = 9;
		bitop->par1 = get_half_c_int(PC_PLUS(2), vm);
		bitop->par2 = get_core_int(PC_PLUS(4), vm);
		bitop->reg_store = get_reg(cursor, CORE_PC_PLUS(8));
	}
	else
		return (jump);
	bitop->success = 1;
	return (jump);
}