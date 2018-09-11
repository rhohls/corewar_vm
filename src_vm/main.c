/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/11 13:57:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void init_vm(t_vm *vm_data)
{
	set_op_tab(vm_data);// whyyyyyy!??!
	vm_data->file_lines = NULL;
	vm_data->cursor_stack = ft_stacknew();
	vm_data->curr_cycle = 0;
	vm_data->nbr_dead = 0;
	vm_data->player_list = ft_stacknew();
}

int main(int argc, char **argv)
{
	t_vm		vm_data;
	t_list		*player_list;
	t_player	*new_player;
	t_list		*node;
	int			i;
		
	/* load info */
	init_vm(&vm_data);

	if (argc < 2)
	{
		ft_putstr("usage!!, needs a file\n");
		exit(0);
	}
	i = 1;
	
	while(i < argc)
	{
		new_player = make_player(argv[i], i);
		// reassign_player_live(new_player);
		node = ft_lstnew(NULL, 0);
		node->content = new_player;
		node->content_size = i;
		// ft_lstaddfront(&player_list, node);
		ft_stackpush(vm_data.player_list, node);
		i++;
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
