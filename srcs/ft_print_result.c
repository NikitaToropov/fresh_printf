#include "ft_printf.h"

int		ft_print_result(const char *str, t_args **first)
{
	int			counter;
	t_args		*list;
	size_t		i;
	char		*p;

	counter = 0;
	list = *first;
	while (str[i])
	{
		if (str[i] == '%')
		{
			list = list->next;
		}
		else
		{
			write(1, &str[i], (list->pass_start - i));
			i = list->pass_start + list->pass_length;
			counter += list->pass_start - i;
		}
	}
	// ft_free_struct(first);
	return (counter);
}