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
<<<<<<< HEAD
<<<<<<< HEAD
	// printf("result %d\n",a);
=======
	//printf("result %d\n",a);
>>>>>>> cbe397eb1b616fa8c7654e19f1f6e90679fa8c83
=======
	// printf("result %d\n",a);
>>>>>>> 66e37c935ff95297bc98b93b22b8e3338032e559
	return (0);	
	
}
