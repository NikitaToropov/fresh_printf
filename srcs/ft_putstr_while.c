#include "ft_printf.h"

void	ft_putstr_while(char const *s, char c)
{
	int		n;

	n = 0;
	while (s[n] != c)
		n++;
	write(1, s, n);
}