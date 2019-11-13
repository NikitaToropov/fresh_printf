#include "ft_printf.h"
// #include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	// printf("%.8f", 3.2/0);
	ft_printf("%12.4s%+ 0.f%", "1st", 3.5, 8562);
	return (0);
}