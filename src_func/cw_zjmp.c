/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 09:08:35 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	cw_zjmp(t_vm *vm, t_cursor *cursor)
{
	int jump;
	
	if (cursor->carry)
		jump = get_half_c_int(WRAP(cursor->pc + 1), vm) % IDX_MOD;
	else
		jump = 3;
	return(jump);
}