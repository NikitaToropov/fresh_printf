#include "ft_printf.h"

void	ft_convert_to_string(s_args *list)
{
	while (list)
	{
		if (list->flags & BINARY)
			ft_put_bits_in_tne_list(list);
		if (list->type != '%' && !(list->string))
			ft_parse_len(list);
		else
			list->string = ft_strdup("%");
		list = list->next;
	}
}

char	ft_slct_type(s_args *list, int counter_arg)
{
	while (list)
	{
		if (list->n_arg_width == counter_arg ||
		list->n_arg_precision == counter_arg ||
		(list->n_arg == counter_arg &&
		(list->type == 'c' || list->type == 's' || list->type == 'p' ||
		list->type == 'd' || list->type == 'i' || list->type == 'o' ||
		list->type == 'u' || list->type == 'x' || list->type == 'X')))
			return ('i');
		if (list->n_arg == counter_arg && list->type == 'f' &&
		list->length != LONG_DOUBLE)
			return ('f');
		if (list->n_arg == counter_arg && list->type == 'f' &&
		list->length == LONG_DOUBLE)
			return ('F');
		list = list->next;
	}
	return ('e');
}

void	ft_put(s_args *list, int n, unsigned long long i_arg, long double f_arg)
{
	while (list)
	{
		if (list->n_arg_width == n && list->width == -1)
			list->width = (int)i_arg;
		if (list->n_arg_precision == n && list->precision == -1)
			list->precision = (int)i_arg;
		if (list->n_arg == n)
		{
			if (ft_slct_type(list, n) == 'i')
				list->int_arg = i_arg;
			else
				list->float_arg = f_arg;
		}
		list = list->next;
	}
}

int		ft_printf(const char *format, ...)
{
	s_args					*first_list;
	va_list					ap;
	int						cntr;
	char					arg_type;

	first_list = ft_format_string_parse((char*)format);
	cntr = 1;
	va_start(ap, format);
	while (cntr)
	{
		arg_type = ft_slct_type(first_list, cntr);
		if (arg_type == 'i')
			ft_put(first_list, cntr, va_arg(ap, long int), 0);
		else if (arg_type == 'f')
			ft_put(first_list, cntr, 0, (long double)va_arg(ap, double));
		else if (arg_type == 'F')
			ft_put(first_list, cntr, 0, va_arg(ap, long double));
		else
			break;
		cntr++;
	}
	va_end(ap);
	ft_convert_to_string(first_list);
	cntr = ft_final_print((char*)format, first_list);
	ft_clear_the_struct(&first_list);
	return (cntr);
}
