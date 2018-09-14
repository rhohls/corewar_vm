/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:28:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/14 08:30:56 by rhohls           ###   ########.fr       */
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
# define EBYTE(x)	(x & 0xFF)

#define REG_BYTE	1
#define DIR_BYTE	4
#define IND_BYTE	2

# define RRR 0b01010100 //84	54		
# define RIR 0b01110100 //116	74		
# define RDR 0b01100100 //100	64		
# define IRR 0b11010100 //212	d4		
# define IIR 0b11110100 //224	e0		
# define IDR 0b11100100 //228	e4		
# define DRR 0b10010100 //148	94		
# define DIR 0b10110100 //180	b4		
# define DDR 0b10100100 //164	a4
# define RRD 0b01011000 //88 	58
# define RDD 0b01101000 //104	68
# define RID 0b01111000 //120	78
# define IR 0b11010000	//208	90		
# define DR 0b10010000	//144	d0
# define R 0b01000000

# define WRAP(x)		(x > MEM_SIZE ? x % MEM_SIZE + MEM_SIZE : x)
# define CURS_CORE(y)	(cursor, vm->core[WRAP(cursor->pc + y)])

typedef struct	s_vm
{
	char		core[MEM_SIZE];
	t_op		op_table[17];
	t_list		*file_lines;
	t_stack		*cursor_stack;
	int			curr_cycle;
	int			cycle_death;
	int			nbr_dead;
	t_stack		*player_list;
	
}				t_vm;

typedef struct	s_player
{
	char		name[PROG_NAME_LENGTH + 1];
	char		*program;
	int			player_num;
	u_int		program_size;
	int			nbr_lives;
	int			alive;
}				t_player;

typedef struct	s_cursor
{
	int			pc;
	int			op_code;
	int			encoding;
	char		reg[REG_NUMBER][REG_SIZE];
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
void		load_players(char *board, t_list *players);

void		init_vm(t_vm *vm);
void		incr_cursor(t_vm *vm);
void		excute_instruction(t_cursor *cursor, t_vm *vm);
int			cycle_death(t_vm *vm);
int			get_int(char *pointer_to_int);
int			get_half_int(char *pointer_to_int);
int			get_byte_int(char *pointer_to_int);
char		*get_reg_info(t_cursor *cursor, int reg_num);
void		swap_bits(int *num);
int			reg_check(t_cursor *cursor, int reg_num);
void		print_game_state(t_vm *vm);
void update_cursor(t_cursor *cursor, t_vm *vm, int cursor_jump);
/*
** Functions
*/

int		cw_null(t_vm *vm, t_cursor *cursor);
int		cw_live(t_vm *vm, t_cursor *cursor);
int		cw_ld(t_vm *vm, t_cursor *cursor);
int		cw_st(t_vm *vm, t_cursor *cursor);
int		cw_add(t_vm *vm, t_cursor *cursor);
int		cw_sub(t_vm *vm, t_cursor *cursor);
int		cw_and(t_vm *vm, t_cursor *cursor);
int		cw_or(t_vm *vm, t_cursor *cursor);
int		cw_xor(t_vm *vm, t_cursor *cursor);
int		cw_zjmp(t_vm *vm, t_cursor *cursor);
int		cw_ldi(t_vm *vm, t_cursor *cursor);
int		cw_sti(t_vm *vm, t_cursor *cursor);
int		cw_fork(t_vm *vm, t_cursor *cursor);
int		cw_lld(t_vm *vm, t_cursor *cursor);
int		cw_lldi(t_vm *vm, t_cursor *cursor);
int		cw_lfork(t_vm *vm, t_cursor *cursor);
int		cw_aff(t_vm *vm, t_cursor *cursor);

#endif