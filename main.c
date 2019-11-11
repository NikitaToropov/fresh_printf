#include "ft_printf.h"
#include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	printf("%d\n", -2147483648);
	ft_printf("%d", -21474836478);
	return (0);
}
