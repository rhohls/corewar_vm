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

#define BASE "0123456789abcdef"
int add(int a, int b)
{
	if (a >b)
		return (a + b);
		
	else
		return (a/b);
}

static void    n_putnbr_hex(int octet)
{
    // char const *base = "0123456789abcdef";
    
    // mvwprintw(DISPLAY(0), y, *x, "%c", BASE[((octet/16) % 16)]);
    printf("%c", BASE[((octet/16) % 16)]);
    // mvwprintw(DISPLAY(1), 1, 1, "%d", ((octet/16) % 16));

    // mvwprintw(DISPLAY(0), y, *x, "%c", BASE[(octet % 16)]);
    // mvwprintw(DISPLAY(1), 1, 4, "%c", BASE[(octet % 16)]);

    // mvwprintw(DISPLAY(1), 1, 4, "%d", BASE[16]);
    printf("%c", BASE[(octet % 16)]);



}

int main()
{
	// printf("char: %c\n", BASE[0]);
	// printf("char: %c\n", BASE[1]);
	// printf("char: %c\n", BASE[2]);
	// printf("char: %c\n", BASE[3]);
	// printf("char: %c\n", BASE[4]);
	// printf("char: %c\n", BASE[5]);
	// printf("char: %c\n", BASE[6]);
	// printf("char: %c\n", BASE[7]);
	// printf("char: %c\n", BASE[8]);
	// printf("char: %c\n", BASE[9]);
	// printf("char: %c\n", BASE[10]);
	// printf("char: %c\n", BASE[11]);
	// printf("char: %c\n", BASE[12]);
	// printf("char: %c\n", BASE[13]);
	// printf("char: %c\n", BASE[14]);
	// printf("char: %c\n", BASE[15]);
	// printf("char: %c\n", BASE[16]);
	// // printf("char: %c\n", BASE[17]);
	// printf("string: %s\n", BASE);
	unsigned char a[3];
	
	a[0] = -5;
	
<<<<<<< HEAD
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
=======
	printf("%02x\n",a[0]);
	n_putnbr_hex(a[0]);
>>>>>>> db1ea8f27a6b45f7a2709d2ae69028f2940f9668
	return (0);	
	
	
	
	char prog[50];
	
	p
	
	
	
}
