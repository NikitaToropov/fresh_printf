#include "ft_printf.h"

unsigned int		ft_strlen(const char *s)
{
	char	*t;

	t = (char*)s;
	while (*t)
		t++;
	return (t - (char*)s);
}
