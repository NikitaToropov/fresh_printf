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
	return (str);
}

void	ft_put_bits(t_args *list)
{
	list->flags &= 0;
	list->num_width = 0;
	list->width = -1;
	list->num_precision = 0;
	list->precision = -1;
	if (list->type == 'f' && list->length != 'F')
		list->string = ft_make_string_bin(&(list->float_arg), sizeof(double));
	else if (list->type == 'f' && list->length == 'F')
		list->string = ft_make_string_bin(&(list->float_arg), 10);
	else if (list->length == 'H' || list->type == 'c')
		list->string = ft_make_string_bin(&(list->int_arg), sizeof(char));
	else if (list->length == 'h')
		list->string = ft_make_string_bin(&(list->int_arg), sizeof(short));
	else if (list->length == 'L')
		list->string = ft_make_string_bin(&(list->int_arg), sizeof(long long));
	else if (list->length == 'l')
		list->string = ft_make_string_bin(&(list->int_arg), sizeof(long int));
	else
		list->string = ft_make_string_bin(&(list->int_arg), sizeof(int));
}