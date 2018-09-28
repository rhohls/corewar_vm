/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:26:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/27 14:26:12 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		extra_flags(t_args *args, t_vm *vm)
{
	if (STR_CMP("dump") == 0)
	{
		args->index++;
		vm->flags.dump = ft_atoi_long(args->argv[args->index]);
		if (vm->flags.dump == 0 && STR_CMP("0") != 0)
			exit_str("Error: Invalid number for dump\n");
	}
	else if (STR_CMP("c") == 0)
		vm->flags.contin = 1;
	else if (STR_CMP("v") == 0)
		vm->flags.verbose = 1;
	else if (STR_CMP("cv") == 0 || STR_CMP("vc") == 0)
	{
		vm->flags.verbose = 1;
		vm->flags.contin = 1;
	}
	else
		return (-1);
	return (1);
}

void	add_flags(t_args *args, t_vm *vm)
{
	while (args->index < args->argc)
	{
		if (args->argv[args->index][0] != '-')
			break ;
		if (STR_CMP("visual") == 0)
			vm->flags.visual = 1;
		else if (STR_CMP("help") == 0)
			print_visu_help();
		else if (STR_CMP("update") == 0)
			vm->flags.update = 1;
		else
		{
			if (extra_flags(args, vm) == -1)
				break ;
		}
		args->index++;
	}
}
