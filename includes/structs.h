/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:40:08 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 16:40:10 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMSTRUCTS_H
# define VMSTRUCTS_H

# include "../libft/includes/libft.h"
# define U_INT unsigned int

typedef struct	s_args
{
	char		**argv;
	int			argc;
	int			index;
}				t_args;

typedef struct	s_flags
{
	int			dump;
	int			contin;
	int			verbose;
	int			visual;
	int			update;
}				t_flags;

typedef struct	s_life
{
	int			last_live_playernum;
	int			nbr_live_calls;
	int			nbr_checkups;
}				t_life;

typedef struct	s_vm
{
	char		core[MEM_SIZE];
	t_op		op_table[17];
	t_list		*file_lines;
	t_stack		*cursor_stack;
	long int	total_cycle;
	int			curr_cycle;
	int			cycle_to_die;
	int			nbr_dead;
	t_stack		*player_list;
	t_flags		flags;
	t_life		life_info;
	t_visual	cwv;
	int			last_curs;
}				t_vm;

typedef struct	s_player
{
	char		name[PROG_NAME_LENGTH + 1];
	char		*program;
	int			player_num;
	int			start_loc;
	U_INT		program_size;
	int			nbr_lives;
	int			alive;
	int			col_num;
}				t_player;

typedef struct	s_cursor
{
	int			player_num;
	int			live_call;
	int			pc;
	int			op_code;
	int			encoding;
	int			reg[REG_NUMBER];
	int			curr_cycle;
	int			carry;
}				t_cursor;

typedef struct	s_param
{
	int			*reg_store;
	int			par1;
	int			par2;
	int			success;
}				t_param;

typedef struct	s_ldi
{
	int			info_to_load;
	int			location_info;
	int			*reg_to_load;
	int			*reg;
	int			jump;
}				t_ldi;

#endif
