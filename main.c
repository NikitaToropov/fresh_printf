#include "ft_printf.h"

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	// ft_printf("%*.76 018#hhx%81.81Lf", 15);
	ft_printf("%8 5.*f %.2#x , %1$.0d", 16, 3.345, 1);
	return (0);
}