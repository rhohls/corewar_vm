/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 12:34:35 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void init_vm(t_vm *vm_data)
{
	set_op_tab(vm_data);
	vm_data->file_lines = NULL;
}

int main(int argc, char **argv)
{
	t_vm	vm_data;
	
	
	/* load info */
	init_vm(&vm_data);
	if (argc < 2)
	{
		ft_putstr("usage!!, needs a file\n");
		exit(0);
	}
	else //for each file loop
	{
		init_vm(&vm_data);
		make_player(argv[1], 1);
		reassign_player_live();
		// add_player to list of players
	}
	
	// make vm space
	// add player program to space
	// add cursors 
	//
	// loop:
	// incr cursor cycle
	// excute if needed
	// 		delta PC
	//
	// check cycle to die
	// kill players
	//
	//
	//
	return (0);
}
