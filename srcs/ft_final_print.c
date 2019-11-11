#include "ft_printf.h"

int		ft_final_print(char *format, s_args *list)
{
	char	*pointer_to_percent;
	int		counter;
	int		print_length;

	counter = 0;
	while (format)
	{
		if (*format == '%' && list)
		{
			print_length = ft_strlen(list->string);
			write(1, list->string, print_length);
			counter += print_length;
			format = ft_strchr(format, list->type) + 1;
			list = list->next;
		}
		if ((pointer_to_percent = ft_strchr(format, '%')))
		{
			print_length = pointer_to_percent - format;
			write(1, format, print_length);
			counter += print_length;
			format = pointer_to_percent;
		}
		else
		{
			print_length = ft_strlen(format);
			write(1, format, print_length);
			counter += print_length;
			break ;
		}
	}
	return (counter);
}

