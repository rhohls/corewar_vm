/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:58:42 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 11:58:54 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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
