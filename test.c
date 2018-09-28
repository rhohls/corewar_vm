/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/12 08:30:33 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm.h"

// typedef struct		s_header
// {
// 	unsigned int		magic;
// 	char				prog_name[PROG_NAME_LENGTH + 1];
// 	unsigned int		prog_size;
// 	char				comment[COMMENT_LENGTH + 1];
// }					t_header;

int main()
{
	char a[9001];
	t_header head;
	
	ft_bzero(&head, sizeof(t_header));
	int fd = open("player.cor", O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU);

	head.prog_size = 20;
	head.magic = COREWAR_EXEC_MAGIC;
	
	swap_bits((int *)&(head.prog_size));
	swap_bits((int *)&(head.magic));

	write(fd, &head, sizeof(t_header));
	
	close(fd);
	return(0);
}