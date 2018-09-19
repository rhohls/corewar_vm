/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 13:55:45 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_players(int player_start, int argc, char **argv, t_vm *vm)
{
	int i;
	t_player	*new_player;
	t_list		*node;
	
	i = player_start;
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

void print_usage(void)
{
	ft_putstr("Usage: ./corewar [-dump N] < [-n N -a N] champion1.cor >  <...>\n");
	ft_putstr("\t-dump N: Dumps the memory after nbr_cycle execution cycles\n\
	(if the game isn’t already over)\n\n");
	// ft_putstr("#####################################################################\n");	
	ft_putstr("\t-n N: Sets the number of the next program. By default, it will\n\
	be the next available number, in parameter order.\n");
	ft_putstr("\t-a N: Sets the load address of the next program. When no\n\
	address is specified, the programs will be evenly sapced.\n");
	exit(0);
}


int	add_flags(int argc, char **argv, t_vm *vm)
{
	
}

int main(int argc, char **argv)
{
	t_vm		vm;
	int			begin_players;
		
	/* load info */
	init_vm(&vm);
	marco_saftey();

	if (argc < 2)
		print_usage();

	
	begin_players = add_flags(argc, argv, &vm);
	
	init_players(begin_players, argc, argv, &vm);
	
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
