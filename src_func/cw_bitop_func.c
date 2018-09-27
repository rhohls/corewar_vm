/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_bitop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:18:03 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/25 16:18:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	bit5(t_vm *vm, t_cursor *cursor, t_param *bitop, t_ldi *bit)
{
	if (cursor->encoding == IDR)
	{
		bit->jump = 9;
		bitop->par1 = get_ind(2, vm, cursor);
		bitop->par2 = get_dir(4, vm, cursor, 0);
		bitop->reg_store = get_reg(8, vm, cursor);
	}
	else
		return (-1);
	return (1);
}

static int	bit4(t_vm *vm, t_cursor *cursor, t_param *bitop, t_ldi *bit)
{
	if (cursor->encoding == DDR)
	{
		bit->jump = 11;
		bitop->par1 = get_dir(2, vm, cursor, 0);
		bitop->par2 = get_dir(6, vm, cursor, 0);
		bitop->reg_store = get_reg(10, vm, cursor);
	}
	else if (cursor->encoding == DIR)
	{
		bit->jump = 9;
		bitop->par1 = get_dir(2, vm, cursor, 0);
		bitop->par2 = get_ind(6, vm, cursor);
		bitop->reg_store = get_reg(8, vm, cursor);
	}
	else
		return (bit5(vm, cursor, bitop, bit));
	return (1);
}

static int	bit3(t_vm *vm, t_cursor *cursor, t_param *bitop, t_ldi *bit)
{
	if (cursor->encoding == RDR)
	{
		bit->jump = 8;
		if (!(bit->reg = get_reg(2, vm, cursor)))
			return (-1);
		bitop->par1 = *(bit->reg);
		bitop->par2 = get_dir(3, vm, cursor, 0);
		bitop->reg_store = get_reg(7, vm, cursor);
	}
	else if (cursor->encoding == DRR)
	{
		bit->jump = 8;
		bitop->par1 = get_dir(2, vm, cursor, 0);
		if (!(bit->reg = get_reg(6, vm, cursor)))
			return (-1);
		bitop->par2 = *(bit->reg);
		bitop->reg_store = get_reg(7, vm, cursor);
	}
	else
		return (bit4(vm, cursor, bitop, bit));
	return (1);
}

static int	bit2(t_vm *vm, t_cursor *cursor, t_param *bitop, t_ldi *bit)
{
	if (cursor->encoding == IRR)
	{
		bit->jump = 6;
		bitop->par1 = get_ind(2, vm, cursor);
		if (!(bit->reg = get_reg(4, vm, cursor)))
			return (-1);
		bitop->par2 = *(bit->reg);
		bitop->reg_store = get_reg(5, vm, cursor);
	}
	else if (cursor->encoding == IIR)
	{
		bit->jump = 7;
		bitop->par1 = get_ind(2, vm, cursor);
		bitop->par2 = get_ind(4, vm, cursor);
		bitop->reg_store = get_reg(6, vm, cursor);
	}
	else
		return (bit3(vm, cursor, bitop, bit));
	return (1);
}

int			bit1(t_vm *vm, t_cursor *cursor, t_param *bitop, t_ldi *bit)
{
	if (cursor->encoding == RRR)
	{
		bit->jump = 5;
		if (!(bit->reg = get_reg(2, vm, cursor)))
			return (-1);
		bitop->par1 = *(bit->reg);
		if (!(bit->reg = get_reg(3, vm, cursor)))
			return (-1);
		bitop->par2 = *(bit->reg);
		bitop->reg_store = get_reg(4, vm, cursor);
	}
	else if (cursor->encoding == RIR)
	{
		bit->jump = 6;
		if (!(bit->reg = get_reg(2, vm, cursor)))
			return (-1);
		bitop->par1 = *(bit->reg);
		bitop->par2 = get_ind(3, vm, cursor);
		bitop->reg_store = get_reg(5, vm, cursor);
	}
	else
		return (bit2(vm, cursor, bitop, bit));
	return (1);
}
