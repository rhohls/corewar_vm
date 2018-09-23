/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 13:34:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	cw_zjmp(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	//printf("- in zjump -\n");
=======
	// printf("- in zjump -\n");
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	int jump;
	
	if (cursor->carry)
	{
		jump = get_dir(1, vm, cursor, 1); 
		jump = jump % IDX_MOD;
	}
	else
		jump = 3;
	return (jump);
}