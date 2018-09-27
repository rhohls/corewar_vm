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
		exit_str("Please reset REG_SIZE to 4\n");
	if (MEM_SIZE != 4096)
		exit_str("Please reset MEM_SIZE to 4096\n");
}

void print_visu_help(void)
{
	ft_putstr("\nThe visualiser is interactive. The following key are enabled:\n");
	ft_putstr("Spacebar    : Pauses the game\n");
	ft_putstr("Left arrow  : Slows down the game\n");
	ft_putstr("Right arrow : Speeds up the game\n");
	ft_putstr("Up arrow    : Resets the speed to max\n");
	ft_putstr("Escape      : Quits the current game\n");	
	exit(0);
}

/*
** The following is messy due to norm
*/

void print_usage(void)
{
	ft_putstr("Usage: ./corewar -help [-visual | -update] [] [-dump N [-c -v]] <[-n N] champion.cor>  <...>\n\n");
	ft_putstr("|--------VM Settings:--------\n");
	ft_putstr("|  -visual: Enables the viualiser mode\n");
	ft_putstr("|  -help: Displays useful information for the VM\n");
	ft_putstr("|  -update: Displays information about the game every cycle\n");	
	ft_putstr("|  -s N: sets initial speed for the visualiser\n");	
	ft_putstr("|  -dump N: Dumps the memory after N execution cycles (if the game isn’t already over)\n");
	ft_putstr("|  -c: Continue, will allow you to continue after dumping\n");
	ft_putstr("|  -v: Verbose, will dump extra info about the game state\n");
	// ft_putstr("#####################################################################\n");	
	ft_putstr("|\n|--------Player Settings:--------\n");	
	ft_putstr("|  -n N: Sets the number of the next program. By default");
	ft_putstr(", it will be the next available number, in parameter order.\n\n");
	exit(0);
}


void	add_flags(t_args *args, t_vm *vm)
{
	while (args->index < args->argc)
	{
		if (args->argv[args->index][0] != '-')
			break ;
		if (STR_CMP("visual"))
			vm->flags.visual = 1;
		else if(STR_CMP("help"))
			print_visu_help();
		else if(STR_CMP("update"))
			vm->flags.update = 1;
		else if (STR_CMP("dump"))
		{
			args->index++;
			vm->flags.dump = ft_atoi_long(args->argv[args->index]);
			if (vm->flags.dump == 0 && ft_strcmp(args->argv[args->index], "0") != 0)
				exit_str("Error: Invalid number for dump\n");
		}
		else if (STR_CMP("c"))
			vm->flags.contin = 1;
		else if (STR_CMP("v"))
			vm->flags.verbose = 1;
		else if (STR_CMP("cv") || STR_CMP("vc"))
		{
			vm->flags.verbose = 1;
			vm->flags.contin = 1;
		}			
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
	
	ft_bzero(vm.core, MEM_SIZE);
	load_players(&vm, vm.core, vm.player_list->start);
	
	if (vm.player_list->length > MAX_PLAYERS)
		exit_str("Error: Too many champions\n");
	
	if (vm.flags.visual)
	{
		if (vm.flags.update)
			exit_str("Please use either visual or update mode\n");
		n_init_curses(&vm);
		n_print_core(&vm);
	}
	vm_loop(&vm);
	endwin();
	return (0);
}
