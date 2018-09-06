/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:28:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 11:27:26 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/includes/libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>


typedef struct	s_asm
{
	t_op		op_table[17];
	t_list		*file_lines;
}				t_asm;





void	read_file(char *file_name, t_asm *asm_data);
void	set_op_tab(t_asm *asm_data);


#endif