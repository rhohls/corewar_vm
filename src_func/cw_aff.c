/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 14:47:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	cw_aff(t_vm *vm, t_cursor *cursor)
{
	int jump;
	int *reg_info;
	
	jump = 1;
	if ((cursor->encoding & R) == R)
	{
		reg_info = (get_reg(cursor, CORE_PC_PLUS(2)));
		ft_printf("Cursor at %d register %d value: %d\n", cursor->pc, 
					CORE_PC_PLUS(2), *reg_info)	;
		jump = 3;
	}
	return (0);
}