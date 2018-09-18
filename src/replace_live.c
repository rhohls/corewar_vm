


// #include "../includes/vm.h"

// static int (*g_func_ptr2[17])(char *program) =
// {// return int = amnt of jumps needed by pc ??/
// 	cw_null, cw_live, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
// 	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
// 	cw_lfork, cw_aff
// };

// int	cw_st(char *program, int index)
// {
// 	if program[index +1] == RRR //encoding byte
// 		return 3
// 	else if ...
// 		return 5;
// }

// while(1)
// {
// 	if index > program_size
// 		break ;
// 	op_code = program[index]
// 	if op_code == 1
// 		replace;
// 	index += jump_function(op_code)
// }

