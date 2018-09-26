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


void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
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
	return(ret == 0 ? 1 : 0);		
}

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
			write(1, "*\n", 2);
		}
		else if (!skip)
		{
			skip_prev = 0;
			if (location)
			{
				ft_putnbr_hex(ind,7);
				write(1, " ", 1);
			}
			a = 0;
			while (a < 16 && a + ind < size)
			{
				ft_putnbr_hex(*(ptr + ind + a), 2);
				write(1, " ", 1);
				a++;
			}
			while (a < 16)
			{
				write(1, "  ", 2);
				if (a % 2)
					write(1, " ", 1);
				a++;
			}
			if (printable)
			{
				a = 0;
				while (a < 16 && a + ind < size)
				{
					sp_putchar(ptr + a + ind);
					a++;
				}
			}
			write(1, "\n", 1);
		}
		ind += 16;
	}
}

void	print_board_location(unsigned char const *core, size_t size)
{
	size_t	ind;
	size_t	a;
	size_t	stop;
	
	stop = 32; // 4096 ^ 0.5
	ind = 0;
	size_t location;
	while (ind < size)
	{
		a = 0;
		location = ind + 1;
		while (location < 1000)
		{
			write(1, "0", 1);
			location *=10;
		}
		ft_putnbr(ind);
		write(1, ": ", 3);
		while (a < stop && a + ind < size)
		{
			ft_putnbr_hex(*(core + ind + a), 2);
			write(1, " ", 1);
			a++;
		}
		write(1, "\n", 1);
		ind += stop;
	}
}

void	print_board(unsigned char const *core, size_t size)
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
			ft_putnbr_hex(*(core + ind + a), 2);
			write(1, " ", 1);
			a++;
		}
		write(1, "\n", 1);
		ind += stop;
	}
}

void	print_player_live(t_vm *vm)
{
	t_list		*node;
	t_player	*player;

	node = vm->player_list->start;
	while (node)
	{
		player = node->content;
		ft_printf("Player: \"%s\" number: %i ", player->name, player->player_num);
		if (player->alive == 0)
			ft_printf("is dead\n");
		else
			ft_printf("has %d lives\n", player->nbr_lives);		
		node = node->next;
	}
}

void	print_cycle_info(t_vm *vm)
{
	ft_printf("Current cycle: %d\t", vm->curr_cycle);
	ft_printf("Cycle to die: %d\t", vm->cycle_to_die);
	ft_printf("Cycle delta: %d\n", CYCLE_DELTA);
}

void	print_cursor_register(t_cursor *cursor)
{
	int i;
	
	i = 0;
	ft_putstr("\tRegister info:\n");
	while (i < REG_NUMBER)
	{
		ft_printf("\t\treg[%d]: %d\n", i + 1, cursor->reg[i]);
		i++;
	}
}

void	print_one_cursor(t_cursor *cursor)
{
	ft_printf("\tCursor location\t- %d\n", cursor->pc);
	ft_printf("\tCurrent OP code\t- %x\n", cursor->op_code);
	// printf("\tCurrent OP code\t- %02x\n", cursor->op_code);
	ft_printf("\tAmt cycles left\t- %d\n", cursor->curr_cycle);
	ft_printf("\tLive call\t- %d\n", cursor->live_call);
	ft_printf("\tCarry\t\t- %d\n", cursor->carry);
	print_cursor_register(cursor);
}

void	print_cursor_info(t_vm *vm)
{
	t_list		*node;
	t_cursor	*cursor;
	int			i;
	
	i = vm->cursor_stack->length;
	
	node = vm->cursor_stack->start;
	while (node)
	{
		cursor = node->content;
		ft_printf("Cursor no. %i is at |%d| with values:\n", i, cursor->pc);
		print_one_cursor(cursor);
		
		node = node->next;
		i--;
	}
}

// -dump nbr_cycles
// at the end of nbr_cycles of executions, dump the memory on the standard output
// and quit the game. The memory must be dumped in the hexadecimal format with
// 32 octets per line.

void	print_game_state(t_vm *vm)
{
	printf("\n");
	print_board((unsigned const char *)(&(vm->core[0])), MEM_SIZE);
	print_cycle_info(vm);
	print_player_live(vm);
	print_cursor_info(vm);
}