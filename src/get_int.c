/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:55:16 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/12 14:16:24 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_bits(int *num)
{
	int b0,b1,b2,b3;
	int res;
	
	b0 = (*num & 0x000000ff) << 24;
	b1 = (*num & 0x0000ff00) << 8;
	b2 = (*num & 0x00ff0000) >> 8;
	b3 = (*num & 0xff000000) >> 24;

	res = b0 | b1 | b2 | b3;
	
	*num = res;
}

int			get_int(char *pointer_to_int)
{
	int	ret;
	int	i;
	
	ret = *((int *)pointer_to_int);
	swap_bits(&ret);
	return (ret);	
}

int			get_half_int(char *pointer_to_int)
{
	int ret;
	int	i;
	char dup[4];
	
	dup[0] = 0;
	dup[1] = 0;
	dup[2] = *pointer_to_int;
	dup[3] = *(pointer_to_int + 1);

	ret = *((int *)dup);
	swap_bits(&ret);
	return (ret);
}

int			get_byte_int(char *pointer_to_int)
{
	int ret;
	int	i;
	char dup[4];
	
	dup[0] = 0;
	dup[1] = 0;
	dup[2] = 0;
	dup[3] = *pointer_to_int;

	ret = *((int *)dup);
	swap_bits(&ret);
	return (ret);
}