/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:28:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/10 13:31:26 by rhohls           ###   ########.fr       */
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
	int			current_cycle;
	
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
	int			carry;
}				t_cursor;

void		exit_str(char *str);
void		exit_errno(void);
void		exit_errnostr(char *str);

t_player	*make_player(char *file_name, int player_num);
void		set_op_tab(t_vm *vm_data);
void		print_memory(const void *addr, size_t size, int printable, int location);
void		swap_bits(int *num);

void		incr_cursor(t_vm *vm);
void		excute_instruction(t_cursor *cursor, t_vm *vm);

/*
** Functions
*/

void		cw_null(t_vm *vm, t_cursor *cursor);
void		cw_live(t_vm *vm, t_cursor *cursor);
void		cw_ld(t_vm *vm, t_cursor *cursor);
void		cw_st(t_vm *vm, t_cursor *cursor);
void		cw_add(t_vm *vm, t_cursor *cursor);
void		cw_sub(t_vm *vm, t_cursor *cursor);
void		cw_and(t_vm *vm, t_cursor *cursor);
void		cw_or(t_vm *vm, t_cursor *cursor);
void		cw_xor(t_vm *vm, t_cursor *cursor);
void		cw_zjmp(t_vm *vm, t_cursor *cursor);
void		cw_ldi(t_vm *vm, t_cursor *cursor);
void		cw_sti(t_vm *vm, t_cursor *cursor);
void		cw_fork(t_vm *vm, t_cursor *cursor);
void		cw_lld(t_vm *vm, t_cursor *cursor);
void		cw_lldi(t_vm *vm, t_cursor *cursor);
void		cw_lfork(t_vm *vm, t_cursor *cursor);
void		cw_aff(t_vm *vm, t_cursor *cursor);

#endif