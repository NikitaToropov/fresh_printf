#include "ft_printf.h"

char		ft_find_type(char *str)
{
	while (*str)
	{
		if (*str == 'c' || *str == 's' || *str == 'p' ||
		*str == 'i' || *str == 'd' || *str == 'u' ||
		*str == 'o' || *str == 'x' || *str == 'X' ||
		*str == 'f' || *str == '%')
			return (*str);
		str++;
	}
	ft_errors(UNKNOWN_CHAR);
	return ('\0');
}

s_args		*ft_make_blank_list(int counter)
{
	s_args			*list;

	if (!(list = malloc(sizeof(s_args))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->order_counter = counter;
	list->n_arg_width = 0;
	list->n_arg_precision = 0;
	list->n_arg = 0;
	list->width = -1;
	list->precision = -1;
	list->int_arg = 0;
	list->float_arg = 0;
	list->float_list = NULL;
	list->flags = 0;
	list->length = 0;
	list->type = 0;
	list->string = NULL;
	list->next = NULL;
	return (list);
}

char		*ft_parse_format_placeholder(char *str, s_args *list)
{
	char			*tmp_list;

	list->type = ft_find_type(str);
	while (*str != list->type)
	{
		tmp_list = str;
		str += ft_find_parameter(str, list);
		str += ft_find_flag(*str, list);
		str += ft_find_width(str, list);
		str += ft_find_precision(str, list);
		str += ft_find_length(str, list);
		if (tmp_list == str)
			ft_errors(UNKNOWN_CHAR);
	}
	list->n_arg = list->order_counter;
	list->order_counter += 1;
	return (str);
}

s_args		*ft_format_string_parse(char *str)
{
	s_args			*list;
	s_args			*first_list;

	first_list = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!first_list)
			{
				first_list = ft_make_blank_list(1);
				list = first_list;
			}
			else
			{
				list->next = ft_make_blank_list(list->order_counter);
				list = list->next;
			}
			str = ft_parse_format_placeholder(str, list);
		}
		str++;
	}
	return (first_list);
}
