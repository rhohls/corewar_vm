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

int	cw_aff(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	// printf("- in aff -\n");
=======
>>>>>>> ae97f6f83d308af68e86413eafb4a05a17944166
	int				jump;
	int				*reg_info;
	unsigned char	print_char;

	jump = 1;
	if ((cursor->encoding & R) == R)
	{
		jump = 3;
		if (!(reg_info = get_reg(2, vm, cursor)))
			return (jump);
		//change to print printable character?
		// %256 & ABS to get char
<<<<<<< HEAD
		
		print_char = (unsigned char)(*reg_info);
		
		// ft_printf("aff operation from cursor at %d from register %d and player number %d\n",
					// cursor->pc, CORE_PC_PLUS(2), cursor->player_num);
		// ft_printf("The info: %c (%d)\n", print_char, *reg_info);
		}
=======
		// print_char = (unsigned char)(*reg_info);
		ft_printf("aff operation from cursor at %d from register %d ",
					cursor->pc, CORE_PC_PLUS(2));
		ft_printf("and player number %d\n", cursor->player_num);
		ft_printf("The info: %c (%d)\n", print_char, *reg_info);
	}
>>>>>>> ae97f6f83d308af68e86413eafb4a05a17944166
	return (3);
}
