#include "ft_printf.h"

void	ft_convert_to_string(s_args *list)
{
	while (list)
	{
		if (ft_arg_is_integer(list->type))
		else if (list->type == 'f' && list->length == LONG_DOUBLE)
		else if (list->type == 'f')
		else
		list = list->next;
	}
}