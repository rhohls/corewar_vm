/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:38:05 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/18 10:05:32 by rhohls           ###   ########.fr       */
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

char		*check_flags(t_args *args, int *player_num, int *player_start)
{
	*player_start = -1;
	while (args->index < args->argc)
	{
		if (args->argv[args->index][0] != '-')
			break ;
		if (ft_strcmp(args->argv[args->index] + 1, "n") == 0)
		{
			args->index++;
			*player_num = ft_atoi_long(args->argv[args->index]);
			if (*player_num == 0)
				exit_str("Error:\nBad player number\n");
		}
		else if (ft_strcmp(args->argv[args->index] + 1, "a") == 0)
		{
			args->index++;
			*player_start = ft_atoi_long(args->argv[args->index]);
		}		
		args->index++;
	}
	return(args->argv[args->index]);
}

t_player	*make_player(t_args *args, int *player_num)
{
	int		fd;
	u_int	prog_size;
	char	*program;
	char	*file_name;
	int		player_start;
	
	file_name = check_flags(args, player_num, &player_start);
	
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
	printf("palyer num: %d\n", *player_num);
	ret_player->player_num = *player_num;
	ret_player->start_location = player_start;
	ret_player->program_size = prog_size;
	ret_player->alive = 1;
	ret_player->nbr_lives = 0;


	return (ret_player);
}


void	init_players(t_args *args, t_vm *vm)
{
	int			player_num;
	t_player	*new_player;
	t_list		*node;
	
	while (args->index < args->argc)
	{
		player_num = -1;
		new_player = make_player(args, &player_num);
		node = ft_lstnew(NULL, 0);
		node->content = new_player;
		node->content_size = player_num;
		ft_stackpush(vm->player_list, node);
		
		printf("After making - player: %s has number %d\n", new_player->name, new_player->player_num);
		args->index++;
	}
}