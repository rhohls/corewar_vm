/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:38:05 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/06 08:22:55 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

#define HEADER_SIZE 2192

void	read_file(char *file_name, t_asm *asm_data)
{
	int fd;
	char	*line;
	int		gnl_ret;
	t_list	*temp;	
	// fd = open(file_name, O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU); this is for writing
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error: There was an error opening file \"%s\"\nReason: ", file_name);
		ft_putendl(strerror(errno));
		exit(0);
	}
	
	char	header[HEADER_SIZE];
	int		read_ret;
	
	read_ret = read(fd, header, HEADER_SIZE);
	
	
		
	
}
