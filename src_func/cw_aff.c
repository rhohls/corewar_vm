/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 14:47:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** change to print printable character?
** %256 & ABS to get char
*/

char	*n_get_player_name(t_vm *vm, t_cursor *cursor)
{	
	int 		i;
	t_list		*player_node;
	t_player	*player;

	player_node = vm->player_list->start;
	i = 1;
	player = player_node->content;
	while (player_node && player->player_num != cursor->player_num)
	{
		player = player_node->content;
		player_node = player_node->next;
	}
	return (player->name);
}

void	n_print_aff(t_vm *vm, t_cursor *cur, int *r_i, unsigned char c)
{
	static int	i = 3;
	int			line;
	char 		*name;

	name = n_get_player_name(vm, cur);
	mvwprintw(DISPLAY(2), i++, 1, "%s says: %c", name, c, *r_i);
	if (i >= SECTION(2).size_x)
	{
		line = 3;
		while (line < SECTION(2).size_x)
		{
			wmove(DISPLAY(2), line++, 1);
			wclrtoeol(DISPLAY(2));
		}
		box(DISPLAY(2), 0, 0);
		i = 3;
	}
}

int		cw_aff(t_vm *vm, t_cursor *cursor)
{
	int				jump;
	int				*reg_info;
	unsigned char	print_char;

	jump = 1;
	if ((cursor->encoding & R) == R)
	{
		jump = 3;
		if (!(reg_info = get_reg(2, vm, cursor)))
			return (jump);
		print_char = (unsigned char)(*reg_info);
		if (vm->flags.visual)
			n_print_aff(vm, cursor, reg_info, print_char);
		else
		{
			ft_printf("aff operation from cursor at %d from register %d ",
						cursor->pc, CORE_PC_PLUS(2));
			ft_printf("and player number %d\n", cursor->player_num);
			ft_printf("The info: %c (%d)\n", print_char, *reg_info);
		}
	}
	return (3);
}
