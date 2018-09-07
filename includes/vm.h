/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:28:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 14:38:37 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/includes/libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define  u_int unsigned int

typedef struct	s_vm
{
	t_op		op_table[17];
	t_list		*file_lines;
	t_stack		*cursor_stack;
	
}				t_vm;

typedef struct	s_player
{
	char		name[PROG_NAME_LENGTH + 1];
	char		*program;
	int			player_num;
	u_int		program_size;
	
}				t_player;

typedef struct	s_cursor
{
	int			pc;
	char		reg[REG_NUMBER];
	int			curr_cycle;
}				t_cursor;

void		exit_str(char *str);
void		exit_errno(void);
void		exit_errnostr(char *str);

t_player	*make_player(char *file_name, int player_num);
void		set_op_tab(t_vm *vm_data);
void		print_memory(const void *addr, size_t size, int printable, int location);

#endif