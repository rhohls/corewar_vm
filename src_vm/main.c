/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 08:00:05 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void init_asm(t_asm *asm_data)
{
	set_op_tab(asm_data);
	asm_data->file_lines = NULL;
}

int main(int argc, char **argv)
{
	t_asm	asm_data;
	
	init_asm(&asm_data);
	
	if (argc < 2)
	{
		ft_putstr("usage!!, needs a file\n");
		exit(0);
	}
	else //for each file loop
	{
		init_asm(&asm_data);
		read_file(argv[1], &asm_data);

	}
	
	
	return (0);
}
