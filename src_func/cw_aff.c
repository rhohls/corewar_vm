/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 14:47:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** change to print printable character?
** %256 & ABS to get char
*/

void	n_print_aff(void)
{
	return ;
}

int		cw_aff(t_vm *vm, t_cursor *cursor)
{
	int				jump;
	int				*reg_info;
	unsigned char	print_char;

	jump = 1;
	if ((cursor->encoding & R) == R)
	{
		jump = 3;
		if (!(reg_info = get_reg(2, vm, cursor)))
			return (jump);
		print_char = (unsigned char)(*reg_info);
		if (vm->flags.visual)
			n_print_aff();
		else
		{
			ft_printf("aff operation from cursor at %d from register %d ",
						cursor->pc, CORE_PC_PLUS(2));
			ft_printf("and player number %d\n", cursor->player_num);
			ft_printf("The info: %c (%d)\n", print_char, *reg_info);
		}
	}
	return (3);
}
