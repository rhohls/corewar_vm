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

void marco_saftey(void)
{
	if (REG_SIZE != 4)
		exit_str("REG_SIZE can not be anything other than 4\n");
}

void print_usage(void)
{
	ft_putstr("Usage: ./corewar [-visual] [-dump N [-c -v]]  <[-n N -a N] champion.cor>  <...>\n\n");
	ft_putstr("|--------VM Settings:--------\n");
	ft_putstr("|  -visual: Enables the viualiser mode\n");
	ft_putstr("|  -dump N: Dumps the memory after N execution cycles (if the game isn’t already over)\n");
	ft_putstr("|  -c: Continue, will allow you to continue after dumping\n");
	ft_putstr("|  -v: Verbose, will dump extra info about the game state\n");
	// ft_putstr("#####################################################################\n");	
	ft_putstr("|\n|--------Player Settings:--------\n");	
	ft_putstr("|  -n N: Sets the number of the next program. By default, it will be the next available number, in parameter order.\n");
	ft_putstr("|  -a N: Sets the load address of the next program. When no address is specified, the programs will be evenly sapced.\n");
	exit(0);
}


void	add_flags(t_args *args, t_vm *vm)
{
	while (args->index < args->argc)
	{
		if (args->argv[args->index][0] != '-')
			break ;
		if (ft_strcmp(args->argv[args->index] + 1, "visual") == 0)
			vm->flags.visual = 1;	
		else if (ft_strcmp(args->argv[args->index] + 1, "dump") == 0)
		{
			args->index++;
			vm->flags.dump = ft_atoi_long(args->argv[args->index]);
			if (vm->flags.dump == 0 && ft_strcmp(args->argv[args->index], "0") != 0)
				exit_str("Error: Invalid number for dump\n");
		}
		else if (ft_strcmp(args->argv[args->index] + 1, "c") == 0)
			vm->flags.contin = 1;
		else if (ft_strcmp(args->argv[args->index] + 1, "v") == 0)
			vm->flags.verbose = 1;
		else
			break ;
		args->index++;
	}
}

void	print_flags(t_vm *vm)
{
	printf("dump: %d\n", vm->flags.dump);
	printf("continue: %d\n", vm->flags.contin);
	printf("verbose: %d\n", vm->flags.verbose);
	printf("visual: %d\n", vm->flags.visual);
}

int main(int argc, char **argv)
{
	t_vm		vm;
	int			begin_players;
	t_args		args;
	
	init_vm(&vm);
	marco_saftey();
	if (argc < 2)
		print_usage();

	args.argv = argv;
	args.argc = argc;
	args.index = 1;

	add_flags(&args, &vm);
	init_players(&args, &vm);
	
	print_flags(&vm);
	// //printf("player_list length %zu\n", vm.player_list->length);
	
	ft_bzero(vm.core, MEM_SIZE);
	load_players(&vm, vm.core, vm.player_list->start);
	
	
	if (vm.player_list->length < 2)
	{
		vm.life_info.last_live_playernum = 
			((t_player *)(vm.player_list->start->content))->player_num;
		display_winner(&vm);
		exit(0);
	}
	else if (vm.player_list->length > MAX_PLAYERS)
		exit_str("Error: Too many champions\n");
	
	print_board_location((const unsigned char *)(&(vm.core[0])), MEM_SIZE);
	//printf("\n~~~~~~~\n");
	
	vm_loop(&vm);
	
	//printf("\n---Final Board ---\n");
	print_game_state(&vm);	
	return (0);
}
