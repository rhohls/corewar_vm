/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:23:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/29 13:47:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_int_len_neg(int num, int *neg)
{
	int num_dig;

	num_dig = 0;
	if (num < 0)
	{
		num *= -1;
		*neg = 1;
	}
	else
		*neg = 0;
	if (num > -10 && num < 10)
		return (num_dig = 1);
	while (num)
	{
		num /= 10;
		num_dig++;
	}
	return (num_dig);
}
