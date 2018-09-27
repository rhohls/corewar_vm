/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_par2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:12:08 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 16:12:12 by ppreez           ###   ########.fr       */
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
