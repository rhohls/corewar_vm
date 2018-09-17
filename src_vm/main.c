/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 13:28:11 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_players(int argc, char **argv, t_vm *vm)
{
	int i;
	t_player	*new_player;
	t_list		*node;
	
	i = 1;
	while (i < argc)
	{
		new_player = make_player(argv[i], i);
		// reassign_player_live(new_player);
		node = ft_lstnew(NULL, 0);
		node->content = new_player;
		node->content_size = i;
		// ft_lstaddfront(&player_list, node);
		ft_stackpush(vm->player_list, node);
		i++;
	}
}

void marco_saftey(void)
{
	if (REG_SIZE < 4)
		exit_str("REG_SIZE cant be less than 4\n");
}

int main(int argc, char **argv)
{
	t_vm		vm;
	int			i;
		
	/* load info */
	init_vm(&vm);
	marco_saftey();

	if (argc < 2)
	{
		ft_putstr("usage!!, needs a file\n");
		exit(0);
	}
	i = 1;
	
	init_players(argc, argv, &vm);
	

	ft_bzero(vm.core, MEM_SIZE);
	load_players(&vm, vm.core, vm.player_list->start);
	printf("\n~~~~~~~\n");
	vm_loop(&vm);
	print_game_state(&vm);
	
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

	return (0);
}
