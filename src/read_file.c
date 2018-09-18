/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:38:05 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 09:58:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define HEADER_SIZE 2192
#include <unistd.h>


u_int		get_prog_size(char *header_at_size)
{
	u_int	ret;
		
	ret = *((u_int *)header_at_size);
	swap_bits((int *)&ret);
	
	return (ret);
}

int			open_file(char *file_name)
{
	int fd;
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error: There was an error opening file \"%s\"\nReason: ", file_name);
		exit_errno();
	}
	return (fd);
}

void		read_header(int fd, u_int *prog_size, char	**program)
{
	char	header[HEADER_SIZE];
	
	if (read(fd, header, HEADER_SIZE) < 1)
		exit_errnostr("Error reading file\n");
	*prog_size = get_prog_size(&header[136]);
	
	// print_memory(header, HEADER_SIZE, 0, 1);
	// printf("progam size is %d\n", prog_size);
	
	*program = (char *)ft_memalloc(*prog_size);
	if (read(fd, program, *prog_size) < 1)
		exit_errnostr("Error reading file\n");
		
	// print_memory(program, prog_size, 0, 1);	
}

t_player	*make_player(char *file_name, int player_num)
{
	int		fd;
	u_int	prog_size;
	char	*program;
	
	fd = open_file(file_name);
	// read_header(fd, &prog_size, &program);
	char	header[HEADER_SIZE];	
	if (read(fd, header, HEADER_SIZE) < 1)
		exit_errnostr("Error reading file\n");
	prog_size = get_prog_size(&header[136]);
	program = (char *)ft_memalloc(prog_size);
	if (read(fd, program, prog_size) < 1)
		exit_errnostr("Error reading file\n");
		
	if (get_point_int(header) != COREWAR_EXEC_MAGIC) 
		exit_str("Error: Magic numbers don't match\n");

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
	ret_player->alive = 1;
	// ret_player->nbr_lives = 0;
	
	int fd1 = open("file.test", O_RDWR);
	printf("writing to file with fd %d\n", fd1);
	write(fd1, program, prog_size);
	close(fd1);
	
	
	

	return (ret_player);
}
