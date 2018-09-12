/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:57:30 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/12 12:25:45 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char		*get_reg_info(t_cursor *cursor, int reg_num)
{
	if (reg_num >= REG_NUMBER || reg_num <= 0)
		return (0);
	return (cursor->reg[reg_num]);
}