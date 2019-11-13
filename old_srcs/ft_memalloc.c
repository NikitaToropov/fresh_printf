#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size)
	{
		if (!(ptr = (unsigned char *)malloc(size)))
			return (NULL);
		while (size)
			ptr[--size] = 0;
	}
	return ((void *)ptr);
}