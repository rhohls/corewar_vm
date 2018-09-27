/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:58:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/17 07:51:02 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_cursor_register(t_cursor *cursor, int fd)
{
	int i;

	i = 0;
	ft_putstr_fd("\tRegister info:\n", fd);
	while (i < REG_NUMBER)
	{
		ft_dprintf(fd, "\t\treg[%d]: %d\n", i + 1, cursor->reg[i]);
		i++;
	}
}

void	print_one_cursor(t_cursor *cursor, int fd)
{
	ft_dprintf(fd, "\tCursor location\t- %d\n", cursor->pc);
	if (cursor->op_code < 16)
		ft_dprintf(fd, "\tCurrent OP code\t- 0%x\n",
		cursor->op_code);
	else
		ft_dprintf(fd, "\tCurrent OP code\t- %x\n", cursor->op_code);
	ft_dprintf(fd, "\tAmt cycles left\t- %d\n", cursor->curr_cycle);
	ft_dprintf(fd, "\tLive call\t- %d\n", cursor->live_call);
	ft_dprintf(fd, "\tCarry\t\t- %d\n", cursor->carry);
	print_cursor_register(cursor, fd);
}

void	print_cursor_info(t_vm *vm, int fd)
{
	t_list		*node;
	t_cursor	*cursor;
	int			i;

	i = vm->cursor_stack->length;
	node = vm->cursor_stack->start;
	while (node)
	{
		cursor = node->content;
		ft_dprintf(fd, "Cursor no. %i is at |%d| with values:\n",
			i, cursor->pc);
		print_one_cursor(cursor, fd);
		node = node->next;
		i--;
	}
}

/*
** -dump nbr_cycles
** at the end of nbr_cycles of executions,
** dump the memory on the standard output
** and quit the game. The memory must be dumped
** in the hexadecimal format with
** 32 octets per line.
*/

void	print_game_state(t_vm *vm, int fd)
{
	printf("\n");
	print_board_location((unsigned const char *)(&(vm->core[0])), MEM_SIZE, fd);
	print_cycle_info(vm, fd);
	print_player_live(vm, fd);
	print_cursor_info(vm, fd);
}
