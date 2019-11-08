#include "ft_printf.h"
#include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	// printf("%30p", 3123456);
	// ft_printf("%p", 0);
	// printf("%>p", 0);

	// ft_printf("%.15x", 2152);
	// printf("%.15x", 2152);


	// ft_printf("%.15f", -2152.0/0);


	// ft_printf("%8 5bLf %.*2$#i , %.0d", 3.345L, 1, 2);
	// ft_printf("%bLf", 3.345L);

	// ft_printf("%+- 010.14f", -3.5);

	ft_printf("%#0+16.0f", 3.5); // AAAAAAAAAAAAAAAAAAAAA
	printf("%#0+16.0f", 3.5);


	// printf("%2147483647i", 3); // check it on your ft_printf
	return (0);
}
