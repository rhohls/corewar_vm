/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/13 13:58:47 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	cw_sti(t_vm *vm, t_cursor *cursor)
{
	// int reg_num;
	char *reg_info;
	int	dest;
	int jump;
	
	dest = 0;
	jump = -1;
	reg_info = get_reg_info(cursor, vm->core[WRAP(cursor->pc + 2)]);
	
	if (EBYTE(cursor->encoding) == RRR)
	{
		dest += get_int(get_reg_info(CURS_CORE(5))); //get info at reg		
		// dest += get_int(get_reg_info(cursor, vm->core[WRAP(cursor->pc + 3)])); //get info at reg
		dest += get_int(get_reg_info(cursor, vm->core[WRAP(cursor->pc + 4)]));
		jump = 5;
	}
	else if (EBYTE(cursor->encoding) == RRD)
	{
		dest += get_int(get_reg_info(cursor, vm->core[WRAP(cursor->pc + 3)]));
		dest += get_half_int(&vm->core[WRAP(cursor->pc + 4)]);
		jump = 6;
	}
	else if (EBYTE(cursor->encoding) == RIR || EBYTE(cursor->encoding) == RDR)
	{
		dest += get_half_int(&vm->core[WRAP(cursor->pc + 3)]);		
		dest += get_int(get_reg_info(cursor, vm->core[WRAP(cursor->pc + 5)]));
		jump = 6;
				
	}
	else if (EBYTE(cursor->encoding) == RID || EBYTE(cursor->encoding) == RDD)
	{
		dest += get_half_int(&vm->core[WRAP(cursor->pc + 3)]);		
		dest += get_half_int(&vm->core[WRAP(cursor->pc + 5)]);
		jump = 7;
	}
	
	if (jump > 0 && reg_info)
	{
		ft_memcpy(&vm->core[WRAP(cursor->pc + dest)], reg_info, REG_SIZE);
	}
	
	return (jump);
}