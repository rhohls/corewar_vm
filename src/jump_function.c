/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:50:07 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/18 15:50:27 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	null_jump(char *program)
{
	return (1);
}

int	live_jump(char *program)
{
	return (5);
}

int ld_jump(char *program)
{
	if (EBYTE(program[1]) == DR)
		return (7);
	else
		return (5);
}

int st_jump(char *program)
{
	if (EBYTE(program[1]) == RI)
		return (5);
	else
		return (4);
}

int	add_jump(char *program)
{
	return (5);
}

int	sub_jump(char *program)
{
	return (5);
}

int	and_jump(char *program)
{
	if (EBYTE(program[1]) == RRR)
		return (5);
	else if (EBYTE(program[1]) == IRR || (EBYTE(program[1]) == RIR))
		return (6);
	else if (EBYTE(program[1]) == IIR)
		return (7);
	else if (EBYTE(program[1]) == DRR || (EBYTE(program[1]) == RDR))
		return (8);
	else if (EBYTE(program[1]) == DIR || (EBYTE(program[1]) == IDR))
		return (9);
	else
		return (11);
}

int	or_jump(char *program)
{
	if (EBYTE(program[1]) == RRR)
		return (5);
	else if (EBYTE(program[1]) == IRR || (EBYTE(program[1]) == RIR))
		return (6);
	else if (EBYTE(program[1]) == IIR)
		return (7);
	else if (EBYTE(program[1]) == DRR || (EBYTE(program[1]) == RDR))
		return (8);
	else if (EBYTE(program[1]) == DIR || (EBYTE(program[1]) == IDR))
		return (9);
	else
		return (11);
}

int	xor_jump(char *program)
{
	if (EBYTE(program[1]) == RRR)
		return (5);
	else if (EBYTE(program[1]) == IRR || (EBYTE(program[1]) == RIR))
		return (6);
	else if (EBYTE(program[1]) == IIR)
		return (7);
	else if (EBYTE(program[1]) == DRR || (EBYTE(program[1]) == RDR))
		return (8);
	else if (EBYTE(program[1]) == DIR || (EBYTE(program[1]) == IDR))
		return (9);
	else
		return (11);
}

int	zjmp_jump(char *program)
{
	return (3);
}

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

int	lfork_jump(char *program)
{
	return (3);
}

int aff_jump(char *program)
{
	return (3);
}
