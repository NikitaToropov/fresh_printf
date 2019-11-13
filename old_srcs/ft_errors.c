#include "ft_printf.h"

void	ft_errors(int code)
{
	if (code == 1)
		write(1, "memory is not alocated\n", 23);
	if (code == 2)
		write(1, "unknow character in a format placeholder\n", 41);
	if (code == 3)
		write(1, "some arguments were skipped\n", 28);
	exit(1);
}
