/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:16:05 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 14:37:53 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	cw_core_cpy(int core_dest, int core_start, int size, t_vm *vm)
{
	if (core_dest + size > MEM_SIZE)
	{
<<<<<<< HEAD
		//printf("fix cwcpy \n");
=======
		// printf("fix cwcpy \n");
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
		exit(0);
	}
	ft_memcpy(&(vm->core[core_dest]), &(vm->core[core_start]), size);
}


void	cw_reg_cpy(int core_dest, char *reg_pointer, int size, t_vm *vm)
{
	ft_memcpy(&(vm->core[core_dest]), reg_pointer, size);
}

