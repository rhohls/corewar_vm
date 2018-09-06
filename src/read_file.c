/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:38:05 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 13:14:03 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define HEADER_SIZE 2192
#include <unistd.h>

u_int		get_prog_size(char *header_at_size)
{
	u_int	ret;
	int	i;
	
	ret = 0;
	i = 0;
	while (i < 4)
	{
		ret += header_at_size[i];
		i++;
	}
	
	return (ret);
}

t_player	*make_player(char *file_name, int player_num)
{
	int		fd;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error: There was an error opening file \"%s\"\nReason: ", file_name);
		exit_errno();
	}
	
	char	header[HEADER_SIZE];
	int		read_ret;
	u_int	prog_size;
	char	*program;
	
	read_ret = read(fd, header, HEADER_SIZE);
	if (read_ret < 1)
		exit_errnostr("Error reading file\n");
	print_memory(header, HEADER_SIZE, 0, 1);
	prog_size = get_prog_size(&header[136]);
	
	program = (char *)ft_memalloc(prog_size);
	read_ret = read(fd, program, prog_size);
	if (read_ret < 1)
		exit_errnostr("Error reading file\n");
	print_memory(program, prog_size, 0, 1);
	
	
	t_player	*ret_player;
	int			i;
	
	ret_player = ft_memalloc(sizeof(t_player));
	i = 0;
	
	while (header[i + 4])
	{
		ret_player->name[i] = header[i + 4];
		i++;		
	}
	ret_player->program = program;
	ret_player->player_num = player_num;
	ret_player->program_size = prog_size;
	
	return (ret_player);
}
