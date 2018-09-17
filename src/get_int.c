/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:55:16 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 13:29:02 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	swap_bits(int *num)
{
	int b0,b1,b2,b3;
	// int res;
	
	b0 = (*num & 0x000000ff) << 24;
	b1 = (*num & 0x0000ff00) << 8;
	b2 = (*num & 0x00ff0000) >> 8;
	b3 = (*num & 0xff000000) >> 24;

	*num = b0 | b1 | b2 | b3;
}

int			get_point_int(char *pointer_to_int)
{
	int	ret;
	int	i;
	
	ret = *((int *)pointer_to_int);
	swap_bits(&ret);
	return (ret);	
}

int			get_core_int(int start_of_int, t_vm *vm)
{
	int	ret;
	char dup[4];
	
	
	dup[0] = vm->core[WRAP(start_of_int)];
	dup[1] = vm->core[WRAP(start_of_int + 1)];
	dup[2] = vm->core[WRAP(start_of_int + 2)];
	dup[3] = vm->core[WRAP(start_of_int + 3)];
	
	ret = *((int *)dup);
	swap_bits(&ret);
	return (ret);	
}

int			get_half_p_int(char *pointer_to_int)//, int size
{
	int ret;
	int	i;
	char dup[4];//char dup[size]
	
	dup[3] = *(pointer_to_int + 1);
	
	// printf("\tval :%d\n", dup[3]);
	
	if (dup[3] < 0)
	{
		dup[0] = 0xff;
		dup[1] = 0xff;
	}
	else
	{
		dup[0] = 0;
		dup[1] = 0;
	}
	dup[2] = *pointer_to_int;
	

	ret = *((int *)dup);
	swap_bits(&ret);
	return (ret);
}

int			get_half_c_int(int start_of_int, t_vm *vm)
{
	int ret;
	int	i;
	char dup[4];
	
	dup[3] = vm->core[WRAP(start_of_int + 1)];
	
	if (dup[3] < 0)
	{
		dup[0] = 0xff;
		dup[1] = 0xff;
	}
	else
	{
		dup[0] = 0;
		dup[1] = 0;
	}
	dup[2] = vm->core[WRAP(start_of_int)];
	
	
	ret = *((int *)dup);
	swap_bits(&ret);
	return (ret);	
}