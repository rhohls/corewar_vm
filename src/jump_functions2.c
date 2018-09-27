/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:57:57 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 11:58:08 by ppreez           ###   ########.fr       */
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

int	ld_jump(char *program)
{
	if (EBYTE(program[1]) == DR)
		return (7);
	else
		return (5);
}

int	st_jump(char *program)
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
