/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 12:45:06 by rhohls           ###   ########.fr       */
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
	t_vm		vm_data;
	t_stack		player_list;
	t_player	*new_player;
	t_list		*node;
	int			i;
		
	/* load info */
	init_vm(&vm_data);
	player_list.length = 0;
	player_list.start = NULL;
	if (argc < 2)
	{
		ft_putstr("usage!!, needs a file\n");
		exit(0);
	}
	i = 0;
	while(i < argc)
	{
		init_vm(&vm_data);
		new_player = make_player(argv[i], i);
		reassign_player_live(new_player);
		node = ft_lstnew(NULL, 0);
		ft_stackpush(&player_list, node);
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
