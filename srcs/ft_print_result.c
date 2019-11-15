#include "ft_printf.h"

int		ft_print_result(char *str, t_args *list)
{
	int			counter;
	char		*tmp;

	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			counter += ft_print_arg(list);
			str = ft_strchr(&str[1], list->type);
			if (*str)
				str++;
			list = list->next;
		}
		else
		{
			if (list && (tmp = ft_strchr(str, '%')))
			{
				write(1, str, (tmp - str));
				counter += tmp - str;
				str = tmp;
			}
			else
			{
				write(1, str, ft_strlen(str));
				counter += ft_strlen(str);
				break ;
			}
		}
	}
	return (counter);
}