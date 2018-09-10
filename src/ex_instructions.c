/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:32:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/10 08:28:07 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void (*func_ptr[17])(t_vm *vm, t_cursor *cursor) =
{
	ft_null, ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and, ft_or,
	ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork, ft_lld, ft_lldi,
	ft_lfork, ft_aff
};

void	excute_instruction(t_cursor *cursor, t_vm *vm)
{
	
}

