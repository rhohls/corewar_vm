/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_functions4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:59:51 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 12:00:05 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	ldi_jump(char *program)
{
	if (EBYTE(program[1]) == RRR)
		return (5);
	else if (EBYTE(program[1]) == IRR || EBYTE(program[1]) == DRR
				|| EBYTE(program[1]) == RDR)
		return (6);
	else
		return (7);
}

int	sti_jump(char *program)
{
	if (EBYTE(program[1]) == RRR)
		return (5);
	else if (EBYTE(program[1]) == RIR || EBYTE(program[1]) == RDR
				|| EBYTE(program[1]) == RRD)
		return (6);
	else
		return (7);
}

int	fork_jump(char *program)
{
	return (3);
}

int	lld_jump(char *program)
{
	if (EBYTE(program[1]) == DR)
		return (7);
	else
		return (5);
}

int	lldi_jump(char *program)
{
	if (EBYTE(program[1]) == RRR)
		return (5);
	else if (EBYTE(program[1]) == IRR || EBYTE(program[1]) == DRR
				|| EBYTE(program[1]) == RDR)
		return (6);
	else
		return (7);
}