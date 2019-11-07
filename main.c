#include "ft_printf.h"

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	// ft_printf("%p", 0);
	// printf("%>p", 0);

	// ft_printf("%.15x", 2152);
	// printf("%.15x", 2152);


	// ft_printf("%.15f", -2152.0/0);


	ft_printf("%8 5bLf %.*2$#i , %.0d", 3.345L, 1, 2);
	// ft_printf("%8 5bLf", 3.345L, 1, 2);
	// ft_printf("%bLf", 3.345L);

	// printf("%s\n", ft_itoa_base(0, 8));
	return (0);
}
