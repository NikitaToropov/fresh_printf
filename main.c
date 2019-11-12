#include "ft_printf.h"
#include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	printf("%.10i\n", -15);
	ft_printf("%.10i\n", -15);
	return (0);
}