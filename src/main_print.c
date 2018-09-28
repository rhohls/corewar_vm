/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:30:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/27 14:30:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_visu_help(void)
{
	ft_putstr("\nThe visualiser is interactive. The following key are ");
	ft_putstr("enabled:\n");
	ft_putstr("Spacebar    : Pauses the game\n");
	ft_putstr("Left arrow  : Slows down the game\n");
	ft_putstr("Right arrow : Speeds up the game\n");
	ft_putstr("Up arrow    : Resets the speed to max\n");
	ft_putstr("Escape      : Quits the current game\n");
	exit(0);
}

/*
** The following is messy due to norm. Thanks Norm!
*/

void	print_usage(void)
{
	ft_putstr("Usage: ./corewar -help [-visual | -update] [] [-dump N ");
	ft_putstr("[-c -v]] <[-n N] champion.cor>  <...>\n\n");
	ft_putstr(" ------------------------VM Settings:-----------------------\n");
	ft_putstr("|  -visual: Enables the viualiser mode\t\t\t    |\n");
	ft_putstr("|  -help: Displays useful information for the VM\t    |\n");
	ft_putstr("|  -update: Displays information about the game every cycle");
	ft_putstr(" |\n|\t\t\t\t\t\t\t    |\n|  -dump N: Dumps the memory after ");
	ft_putstr("N execution cycles\t    |\n");
	ft_putstr("|          (if the game isn’t already over)\t\t    |\n|  -c");
	ft_putstr(": Continue, will allow you to continue after dumping   |\n| ");
	ft_putstr(" -v: Verbose, will dump extra info about the game state   |\n");
	ft_putstr("|\t\t\t\t\t\t\t    |\n");
	ft_putstr("| --------------------Player Settings:--------------------- ");
	ft_putstr(
		"|\n|  -n N: Sets the number of the next program. By default,   |\n");
	ft_putstr(
		"| it will be the next available number, in parameter order. |\n");
	ft_putstr(" ---------------------------------------------------------- \n");
	exit(0);
}
