/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 10:50:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	lfork par1
**	create new cursor, inherates state
**	loads cursor at par1
*/

int	cw_lfork(t_vm *vm, t_cursor *cursor)
{
<<<<<<< HEAD
	//printf("- in lfork -\n");
	int		jump;
=======
	// printf("- in lfork -\n");
	t_cursor	*new_cursor;
	int			new_pc;
	int			i;
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	
	jump = cw_forking(vm, cursor, 1);
	return (jump);
}