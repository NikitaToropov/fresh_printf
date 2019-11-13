#include "ft_printf.h"
// #include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>


int		main(void)
{	
	long long int		i = -867;
	// printf("%.8f", 3.2/0);
	ft_printf("%12.4lli%+ 0.Lf%", i, 34.5L, 8562);
	return (0);
}