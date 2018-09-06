/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:21:45 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/23 14:30:14 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/libft.h"

#include <stdio.h>

static char		*line_and_adjust_str(char *str, t_list *curr_node)
{
	int		i;
	int		len;
	char	*ret;
	char	*temp;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	ret = ft_strsub(str, 0, i);
	if (!str[i] || (str[i] && !str[i + 1]))
	{
		ft_strdel(&str);
		curr_node->STRING = str;
		return (ret);
	}
	temp = str;
	str = ft_strdup(str + i + 1);
	free(temp);
	curr_node->STRING = str;
	return (ret);
}

static t_list	*find_fd_str(const int fd, t_list **list)
{
	t_list		*curr_node;

	curr_node = *list;
	while (curr_node)
	{
		if ((int)curr_node->FD == fd)
			return (curr_node);
		curr_node = curr_node->next;
	}
	curr_node = ft_lstnew(0, fd);
	curr_node->STRING = ft_strnew(1);
	curr_node->FD = fd;
	ft_lstadd(list, curr_node);
	return (curr_node);
}

int				gnl_read(const int fd, char **str)
{
	int		read_ret;
	char	buffstr[BUFF_SIZE + 1];

	while (!(ft_strchr(*str, '\n')))
	{
		read_ret = read(fd, buffstr, BUFF_SIZE);
		if (read_ret == -1)
			return (-1);
		buffstr[read_ret] = '\0';
		*str = ft_strjoinfree(*str, buffstr);
		if (read_ret == 0)
		{
			if (**str == '\0')
			{
				free(*str);
				*str = NULL;
				return (0);
			}
			break ;
		}
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*listhold;
	t_list			*curr_node;
	char			*str;
	int				gnl_read_ret;

	if (BUFF_SIZE <= 0 || !line || (fd < -1))
		return (-1);
	curr_node = find_fd_str(fd, &listhold);
	str = curr_node->STRING;
	if (!str)
		str = ft_strnew(1);
	gnl_read_ret = gnl_read(fd, &str);
	if (gnl_read_ret != 1)
		return (gnl_read_ret);
	*line = line_and_adjust_str(str, curr_node);
	return (1);
}
