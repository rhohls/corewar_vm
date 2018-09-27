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

void			marco_saftey(void)
{
	if (REG_SIZE != 4)
		exit_str("Please reset REG_SIZE to 4\n");
	if (MEM_SIZE != 4096)
		exit_str("Please reset MEM_SIZE to 4096\n");
	if (REG_NUMBER < 16)
		exit_str("Please reset REG_NUMBER to 16\n");
}

void			check_visual_flag(t_vm *vm)
{
	if (vm->flags.update)
		exit_str("Please use either visual or update mode\n");
	n_init_curses(vm);
	n_print_core(vm);
}

int				main(int argc, char **argv)
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
		check_visual_flag(&vm);
	vm_loop(&vm);
	endwin();
	exit(0);
	return (0);
}
