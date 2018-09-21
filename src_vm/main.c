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
		exit_str("REG_SIZE cant be less than 4\n");
}

void print_usage(void)
{
	ft_putstr("Usage: ./corewar [-dump [-c -v] N]  <[-n N -a N] champion1.cor>  <...>\n");
	ft_putstr("\t-dump N: Dumps the memory after nbr_cycle execution cycles (if the game isn’t already over)\n");
	ft_putstr("\t-c: Continue, will allow you to continue after dumping\n");
	ft_putstr("\t-v: Verbose, will dump extra info about the game state\n\n");
	// ft_putstr("#####################################################################\n");	
	ft_putstr("\t-n N: Sets the number of the next program. By default, it will be the next available number, in parameter order.\n");
	ft_putstr("\t-a N: Sets the load address of the next program. When no address is specified, the programs will be evenly sapced.\n");
	exit(0);
	
}


void	add_flags(t_args *args, t_vm *vm)
{
	while (args->index < args->argc)
	{
		if (args->argv[args->index][0] != '-')
			break ;
		if (ft_strcmp(args->argv[args->index] + 1, "dump") == 0)
		{
			args->index++;
			vm->flags.dump = ft_atoi_long(args->argv[args->index]);
		}
		args->index++;
	}
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
	printf("player start: %d\n", begin_players);
	printf("dump? %d\n", vm.flags.dump);
	
	init_players(&args, &vm);
	
	
	
	ft_bzero(vm.core, MEM_SIZE);
	load_players(&vm, vm.core, vm.player_list->start);
	
	print_board_location((const unsigned char *)(&(vm.core[0])), MEM_SIZE);
	int i = 311;
	printf("info at %i is %d\n ", i, get_core_int(i + 2, &vm));
	printf("\n~~~~~~~\n");
	vm_loop(&vm);
	print_game_state(&vm);
	


	
	return (0);
}
