/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapbits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:55:16 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/07 07:55:17 by rhohls           ###   ########.fr       */
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