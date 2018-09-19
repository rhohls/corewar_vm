/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:57:30 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 15:00:14 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			reg_check(t_cursor *cursor, int reg_num)
{
	if ((reg_num < REG_NUMBER || reg_num >= 0) && cursor)
		return (1);
	else
		return (0);
}

int			*get_reg(t_cursor *cursor, int reg_num)
{
	if (reg_check(cursor, reg_num))
		return (&(cursor->reg[reg_num]));
	else
		return (NULL);
}