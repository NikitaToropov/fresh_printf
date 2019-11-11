#include "ft_printf.h"

char	*ft_put_bits(void *c, int len)
{
	unsigned char	scanner;
	unsigned char	*byte;
	char			*str;
	unsigned int	pos;

	str = (char*)malloc(sizeof(char) * (len * 8 + (len * 2 - 1) + 1));
	byte = (unsigned char*)c + len - 1;
	pos = 0;
	while (byte >= (unsigned char*)c)
	{
		scanner = 128;
		while (scanner)
		{
			if (*byte & scanner)
				str[pos++] = '1';
			else
				str[pos++] = '0';
			if (scanner == 16 || (scanner == 1 && byte != (unsigned char*)c))
				str[pos++] = ' ';
			scanner /= 2;
		}
		byte--;
	}
	str[pos] = '\0';
	return (str);
}

void	ft_put_bits_in_tne_list(s_args *list)
{
	int		len;

	if (list->type == 'f')
	{
		if (list->length == LONG_DOUBLE)
			len = 10;
		else
			len = sizeof(double);
		list->string = ft_put_bits(&(list->float_arg), len);
	}
	else if (list->type == 'd' || list->type == 'i' ||
	list->type == 'u' || list->type == 'c')
	{
		if (list->length == 'H' || list->type == 'c')
			len = sizeof(char);
		else if (list->length == 'h')
			len = sizeof(short);
		else if (list->length == 'L')
			len = sizeof(long long int);
		else if (list->length == 'l')
			len = sizeof(long int);
		else
			len = sizeof(int);
		list->string = ft_put_bits(&(list->int_arg), len);
	}
	else
		list->flags &= ~BINARY;
}
