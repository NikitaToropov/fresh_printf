#include "ft_printf.h"
// #include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>


int		main(void)
{	
	long long int		i = -867;

	ft_printf("%12.4lli%+ 0.Lf%", i, -152.0L, 8562);
	return (0);
}