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

static char g_strings[4][10] = {"test", "str2", "fsef", "\0"};

int main()
{
	char *str;
	int i;
	
	i = 0;		
	str = g_strings[0];
	
	g_strings[0][3] = 0x12;
	
	i = g_strings[0][3];
	printf("int i = %d %x\n", i, i);
	g_strings[0][3]++;
	
	i = g_strings[0][3];
	printf("int i = %d %x\n", i, i);
	// while (i < 4)
	// {
	// 	printf("%s \n", g_strings[i]);
	// 	i++;
	// }
	
	return (0);	
	
}
