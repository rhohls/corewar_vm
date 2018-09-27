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

#include <unistd.h>
#include "../includes/vm.h"

void	putnbr_hex(int octet, int rem, int fd)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		putnbr_hex(octet >> 4, rem - 1, fd);
	write(fd, base + (octet % 16), 1);
}

void	mem_putchar(unsigned char const *ptr, int fd)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(fd, ptr, 1);
	else
		write(fd, ".", 1);
}

int		check_line(unsigned char const *addr)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < 16)
	{
		ret += addr[i];
		i++;
	}
	return (ret == 0 ? 1 : 0);
}
/*
// delete this
void	print_memory(const void *addr, size_t size, int printable, int location)
{
	size_t	ind;
	size_t	a;
	int		skip;
	int		skip_prev;
	unsigned char const *ptr = addr;

	ind = 0;
	skip_prev = 0;
	while (ind < size)
	{
		skip = check_line(&(ptr[ind]));
		if (skip && !skip_prev)
		{
			skip_prev = 1;
			write(fd, "*\n", 2);
		}
		else if (!skip)
		{
			skip_prev = 0;
			if (location)
			{
				putnbr_hex(ind, 7);
				write(fd, " ", 1);
			}
			a = 0;
			while (a < 16 && a + ind < size)
			{
				putnbr_hex(*(ptr + ind + a), 2);
				write(fd, " ", 1);
				a++;
			}
			while (a < 16)
			{
				write(fd, "  ", 2);
				if (a % 2)
					write(fd, " ", 1);
				a++;
			}
			if (printable)
			{
				a = 0;
				while (a < 16 && a + ind < size)
				{
					mem_putchar(ptr + a + ind);
					a++;
				}
			}
			write(fd, "\n", 1);
		}
		ind += 16;
	}
}
*/
void	print_board_location(unsigned char const *core, size_t size, int fd)
{
	size_t	ind;
	size_t	a;
	size_t	stop;
	size_t location;
	
	stop = 64; // 4096 ^ 0.5
	ind = 0;
	while (ind < size)
	{
		a = 0;
		location = ind + 1;
		while (location < 1000)
		{
			write(fd, "0", 1);
			location *= 10;
		}
		ft_putnbr_fd(ind, fd);
		write(fd, ": ", 3);
		while (a < stop && a + ind < size)
		{
			putnbr_hex(*(core + ind + a), 2, fd);
			write(fd, " ", 1);
			a++;
		}
		write(fd, "\n", 1);
		ind += stop;
	}
}

void	print_board(unsigned char const *core, size_t size, int fd)
{
	size_t	ind;
	size_t	a;
	size_t	stop;

	stop = 64; // 4096 ^ 0.5
	ind = 0;
	while (ind < size)
	{
		a = 0;
		while (a < stop && a + ind < size)
		{
			putnbr_hex(*(core + ind + a), 2, fd);
			write(fd, " ", 1);
			a++;
		}
		write(fd, "\n", 1);
		ind += stop;
	}
}

void	print_player_live(t_vm *vm, int fd)
{
	t_list		*node;
	t_player	*player;

	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		ft_dprintf(fd, "Player: \"%s\" number: %i ", player->name,
					player->player_num);
		if (player->alive == 0)
			ft_dprintf(fd, "is dead\n");
		else
			ft_dprintf(fd, "has %d lives\n", player->nbr_lives);
		node = node->next;
	}
}

void	print_cycle_info(t_vm *vm, int fd)
{
	ft_dprintf(fd, "Current cycle: %d\t", vm->curr_cycle);
	ft_dprintf(fd, "Cycle to die: %d\t", vm->cycle_to_die);
	ft_dprintf(fd, "Cycle delta: %d\n", CYCLE_DELTA);
}

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
		ft_dprintf(fd, "\tCurrent OP code\t- 0%x\n", cursor->op_code);
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
		ft_dprintf(fd, "Cursor no. %i is at |%d| with values:\n", i, cursor->pc);
		print_one_cursor(cursor, fd);
		node = node->next;
		i--;
	}
}

// -dump nbr_cycles
// at the end of nbr_cycles of executions, dump the memory on the standard output
// and quit the game. The memory must be dumped in the hexadecimal format with
// 32 octets per line.

void	print_game_state(t_vm *vm, int fd)
{
	printf("\n");
	print_board((unsigned const char *)(&(vm->core[0])), MEM_SIZE, fd);
	print_cycle_info(vm, fd);
	print_player_live(vm, fd);
	print_cursor_info(vm, fd);
}
