#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		ln;
	
	ln = 0;
	while (s1 && s1[ln])
		ln++;
	res = (char*)malloc(sizeof(char) * (ln + 1));
	if (!res)
		ft_errors(MEM_IS_NOT_ALLOC);
	res[ln] = '\0';
	ln--;
	while (ln >= 0)
	{
		res[ln] = s1[ln];
		ln--;
	}
	return (res);
}
