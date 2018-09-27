/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:43:10 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 10:17:01 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	exit_errnostr(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl(strerror(errno));
	exit(0);
}

void	exit_errno(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(0);
}

void	exit_str(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}
