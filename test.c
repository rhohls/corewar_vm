/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:11:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/11 12:42:34 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm.h"

static char g_strings[4][10] = {"test", "str2", "fsef", "\0"};

int main()
{
	char *str;
	int i;
	
	i = 0;		
	str = strings[0];
	
	while (i < 4)
	{
		printf("%s \n", strings[i]);
		i++;
	}
	
	return (0);	
	
}
