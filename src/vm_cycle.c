/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:30:54 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/10 07:33:57 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	display_winner(t_vm *vm)
{
	
}

int		cycle_death(t_vm *vm)
{
	int	stop;
	
	stop = 0;
	return (stop);
}

void	vm_loop(t_vm *vm)
{
	while(1)
	{
		incr_cursor(vm);
		if (cycle_death(vm))
			break ;
	}
	display_winner(vm);
	// free everything?
}

