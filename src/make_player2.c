/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:24:12 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 16:24:21 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

U_INT		get_prog_size(char *header_at_size)
{
	U_INT	ret;

	ret = *((U_INT *)header_at_size);
	swap_bits((int *)&ret);
	return (ret);
}

int			open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		printf("Error: There was an error opening file \"%s\"\nReason: ",
			file_name);
		exit_errno();
	}
	return (fd);
}

void		read_header(int fd, U_INT *prog_size, char **program)
{
	char	header[HEADER_SIZE];

	if (read(fd, header, HEADER_SIZE) < 1)
		exit_errnostr("Error reading file\n");
	*prog_size = get_prog_size(&header[136]);
	*program = (char *)ft_memalloc(*prog_size);
	if (read(fd, program, *prog_size) < 1)
		exit_errnostr("Error reading file\n");
}
