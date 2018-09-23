/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.FR>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:13:27 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/19 10:39:55 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CWV_H
# define CWV_H

# include <ncurses.h>
# include <panel.h>
# include "../../corewar_vm/includes/vm.h"
# include "../../corewar_vm/includes/op.h"

# define DISPLAY(x)	vm->cwv.window[x]
# define SECTION(x) vm->cwv.section[x]
# define OCTET		64

typedef struct 	s_section
{
	int			start_x;
	int			start_y;
	int			size_x;
	int			size_y;
}				t_section;

typedef struct	s_visual
{
	WINDOW		*window[3];
	PANEL		*panel[3];
	t_section	section[3];
	int			mode;
<<<<<<< HEAD
	int			fd;
=======
	int			win_x;
	int			win_y;
	int			fd;
	char		core[MEM_SIZE];
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
}				t_visual;

#endif
