#include "ft_printf.h"

char	*ft_make_string_bin(void *c, int len)
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
				str[pos] = '1';
			else
				str[pos] = '0';
			pos++;
			if (scanner == 16 || (scanner == 1 && byte != (unsigned char*)c))
			{
				str[pos] = ' ';
				pos++;
			}
			scanner /= 2;
		}
		byte--;
	}

	str[pos] = '\0';
	// write(1, "\nwrong\n\n", 8); //-----------------------------------------------------------------

	return (str);
}

void	ft_put_bits(void *c, s_args *list)
{
	int		len;

	if (list->type == 'f')
	{
		if (list->length == 'F')
			len = 10;
		else
			len = sizeof(double);
	}
	else
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
	}
	list->arg = ft_make_string_bin(c, len);
}