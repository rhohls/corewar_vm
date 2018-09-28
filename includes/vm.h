/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:28:33 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 14:57:02 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "cwv.h"
# include "structs.h"
# include "../libft/includes/libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>

# define U_INT unsigned int
# define EBYTE(x)	(x & 0xff)

# define REG_BYTE	1
# define DIR_BYTE	4
# define IND_BYTE	2

# define RRR 0b01010100
# define RIR 0b01110100
# define RDR 0b01100100
# define IRR 0b11010100
# define IIR 0b11110100
# define IDR 0b11100100
# define DRR 0b10010100
# define DIR 0b10110100
# define DDR 0b10100100
# define RRD 0b01011000
# define RDD 0b01101000
# define RID 0b01111000
# define IR  0b11010000
# define DR  0b10010000
# define RR  0b01010000
# define RI  0b01110000
# define R   0b01000000

# define MS					MEM_SIZE
# define WRAP(x)			((x) % MS < 0 ? (((x) % MS) + MS) : ((x) % MS))
# define CORE_PC_PLUS(x)	EBYTE(vm->core[WRAP(cursor->pc + x)])
# define PC_PLUS(x)			WRAP(cursor->pc + x)
# define ABS(x)				x >= 0 ? x : x * -1
# define STR_CMP(x)			ft_strcmp(args->argv[args->index] + 1, (x))
# define HEADER_SIZE		2192

void		exit_str(char *str);
void		exit_errno(void);
void		exit_errnostr(char *str);

int			get_point_int(char *pointer_to_int);
int			get_half_p_int(char *pointer_to_int);
int			get_core_int(int start_of_int, t_vm *vm);
int			get_half_c_int(int start_of_int, t_vm *vm);
void		store_core_int(int number, int cds, t_vm *vm, int pn);

int			*get_reg(int relative_pc, t_vm *vm, t_cursor *cursor);
int			get_dir(int relative_pc, t_vm *vm, t_cursor *cursor, int half_size);
int			get_ind(int relative_pc, t_vm *vm, t_cursor *cursor);
int			get_ind_nomod(int relative_pc, t_vm *vm, t_cursor *cursor);

void		cw_core_cpy(int core_dest, int core_start, int size, t_vm *vm);
void		cw_reg_cpy(int core_dest, char *reg_pointer, int size, t_vm *vm);

t_player	*make_player(t_args *args, t_vm *vm);
void		check_progam(t_player *player);
U_INT		get_prog_size(char *header_at_size);
int			open_file(char *file_name);
void		read_header(t_player *player, int fd);

int			get_colour_ref(t_vm *vm, int num);
void		set_op_tab(t_vm *vm_data);
void		display_winner(t_vm *vm);

void		swap_bits(int *num);
void		load_players(t_vm *vm, char *board, t_list *players);
t_cursor	*create_cursor(t_vm *vm, int pc);
void		vm_loop(t_vm *vm);

void		init_vm(t_vm *vm);
void		add_flags(t_args *args, t_vm *vm);
void		replace_live(t_vm *vm, t_list *players);
void		init_players(t_args *args, t_vm *vm);
void		name_replacer(t_vm *vm, t_list *player);
void		incr_all_cursor(t_vm *vm, int *print);
void		excute_instruction(t_cursor *cursor, t_vm *vm);
int			cycle_checkup(t_vm *vm);

void		swap_bits(int *num);
int			reg_check(t_cursor *cursor, int reg_num);
t_player	*get_player(t_vm *vm, int player_num);
int			is_duplicate_player_num(int number, t_vm *vm);

void		update_cursor_info(t_cursor *cursor, t_vm *vm, int cursor_jump);
void		add_initial_player_cursor(t_vm *vm, int pc, t_player *player);
void		kill_cursor(t_cursor *cursor, t_vm *vm);
void		add_cursor_to_cursorlist(t_vm *vm, t_cursor *new_cursor);

/*
**	Printing
*/

void		print_memory(const void *addr, size_t size, int print, int loc);
void		print_game_state(t_vm *vm, int fd);
void		print_board_location(unsigned char const *core, size_t s, int fd);
void		print_board(unsigned char const *core, size_t size, int fd);
void		print_cycle_info(t_vm *vm, int fd);
void		print_player_live(t_vm *vm, int fd);

void		print_visu_help(void);
void		print_usage(void);
void		putnbr_hex(int octet, int rem, int fd);

/*
**	Functions
*/

int			cw_null(t_vm *vm, t_cursor *cursor);
int			cw_live(t_vm *vm, t_cursor *cursor);
int			cw_ld(t_vm *vm, t_cursor *cursor);
int			cw_st(t_vm *vm, t_cursor *cursor);
int			cw_add(t_vm *vm, t_cursor *cursor);
int			cw_sub(t_vm *vm, t_cursor *cursor);
int			cw_and(t_vm *vm, t_cursor *cursor);
int			cw_or(t_vm *vm, t_cursor *cursor);
int			cw_xor(t_vm *vm, t_cursor *cursor);
int			cw_zjmp(t_vm *vm, t_cursor *cursor);
int			cw_ldi(t_vm *vm, t_cursor *cursor);
int			cw_sti(t_vm *vm, t_cursor *cursor);
int			cw_fork(t_vm *vm, t_cursor *cursor);
int			cw_lld(t_vm *vm, t_cursor *cursor);
int			cw_lldi(t_vm *vm, t_cursor *cursor);
int			cw_lfork(t_vm *vm, t_cursor *cursor);
int			cw_aff(t_vm *vm, t_cursor *cursor);
int			cw_bitop(t_vm *vm, t_cursor *cursor, t_param *param);
int			cw_math(t_vm *vm, t_cursor *cursor, t_param *param, int type);
int			cw_load(t_vm *vm, t_cursor *cursor, int long_ld);
int			cw_load_i(t_vm *vm, t_cursor *cursor, int long_ld);
int			cw_forking(t_vm *vm, t_cursor *cursor, int long_fk);
int			bit1(t_vm *vm, t_cursor *cursor, t_param *bitop, t_ldi *bit);
/*
**	Jump functions
*/

int			null_jump(char *program);
int			live_jump(char *program);
int			ld_jump(char *program);
int			st_jump(char *program);
int			add_jump(char *program);
int			sub_jump(char *program);
int			and_jump(char *program);
int			or_jump(char *program);
int			xor_jump(char *program);
int			zjmp_jump(char *program);
int			ldi_jump(char *program);
int			sti_jump(char *program);
int			fork_jump(char *program);
int			lld_jump(char *program);
int			lldi_jump(char *program);
int			lfork_jump(char *program);
int			aff_jump(char *program);

/*
**	Visualiser functions
*/

void		n_init_curses(t_vm *vm);
void		n_init_windows(t_vm *vm, int win);
void		n_init_sizes(t_vm *vm);
void		n_init_color_pairs();
void		n_print_core(t_vm *vm);
void		n_print_game_state(t_vm *vm);
void		n_print_cursor(t_vm *vm);
void		n_refresh_all(t_vm *vm);
void		n_putnbr_hex(t_vm *vm, int byte, int *x_y, int col);
void		n_display_winner(t_vm *vm, t_player *player);
void		n_reset_cursor(t_vm *vm);
void		n_print_one_cursor(t_vm *vm, t_cursor *cursor);
int			get_colour(t_vm *vm, int core_index);
void		n_key_get(t_vm *vm);
void		n_print_names(t_vm *vm);
void		n_print_cycles(t_vm *vm);
void		n_print_life_info(t_vm *vm);
int			n_dump(t_vm *vm, WINDOW *display, int x, int y);
void		n_assign_col(t_vm *vm);
int			n_get_col(t_vm *vm, int num);

#endif
