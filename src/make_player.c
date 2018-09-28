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

/*
** Assigns player flag info
** also returns the File name of the player
*/

char		*check_player_flags(t_args *args, t_player *player, t_vm *vm)
{
	player->player_num = -1;
	player->start_loc = -1;
	while (args->index < args->argc)
	{
		if (args->argv[args->index][0] != '-')
			break ;
		if (ft_strcmp(args->argv[args->index] + 1, "n") == 0)
		{
			args->index++;
			player->player_num = ft_atoi_long(args->argv[args->index]);
			if (player->player_num == 0 ||
					is_duplicate_player_num(player->player_num, vm))
				exit_str("Error:\nBad player number\n");
		}
		else if (ft_strcmp(args->argv[args->index] + 1, "a") == 0)
		{
			args->index++;
			player->start_loc = ft_atoi_long(args->argv[args->index]);
		}
		args->index++;
	}
	return (args->argv[args->index]);
}

t_player	*make_player(t_args *args, t_vm *vm)
{
	t_player	*player;
	int			fd;
	char		*file_name;
	int			player_start;

	player = ft_memalloc(sizeof(t_player));
	file_name = check_player_flags(args, player, vm);
	fd = open_file(file_name);
	read_header(player, fd);
	player->alive = 1;
	player->nbr_lives = 0;
	player->program = (char *)ft_memalloc(player->program_size);
	if (read(fd, player->program, player->program_size) < player->program_size)
		exit_errnostr("Error reading file:\n");
	check_progam(player);
	close(fd);
	return (player);
}

int			is_duplicate_player_num(int number, t_vm *vm)
{
	t_list	*player_node;

	player_node = vm->player_list->start;
	while (player_node)
	{
		if (player_node->content_size == number)
			return (1);
		player_node = player_node->next;
	}
	return (0);
}

void		reassign_player_number(t_vm *vm)
{
	int			curr_min_num;
	t_player	*new_player;
	t_list		*node;

	node = vm->player_list->start;
	curr_min_num = 1;
	while (node)
	{
		if (node->content_size == -1)
		{
			while (is_duplicate_player_num(curr_min_num, vm))
				curr_min_num++;
			node->content_size = curr_min_num;
			((t_player *)(node->content))->player_num = curr_min_num;
		}
		node = node->next;
	}
}

void		init_players(t_args *args, t_vm *vm)
{
	t_player	*new_player;
	t_list		*node;

	while (args->index < args->argc)
	{
		new_player = make_player(args, vm);
		node = ft_lstnew(NULL, 0);
		node->content = new_player;
		node->content_size = new_player->player_num;
		ft_stackpush(vm->player_list, node);
		args->index++;
	}
	reassign_player_number(vm);
}
