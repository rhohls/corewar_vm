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
#include <stdio.h>
static char g_strings[4][10] = {"test", "str2", "fsef", "\0"};

int add(int a, int b)
{
	if (a >b)
		return (a + b);
		
	else
		return (a/b);
}

int main()
{
	int a;
	
	a = add(10, 5);
	// printf("result %d\n",a);
	return (0);	
	
}
