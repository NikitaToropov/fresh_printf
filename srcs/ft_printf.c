#include "ft_printf.h"

void	ft_convert_to_string(s_args *list)
{
	while (list)
	{
		if (list->flags & BINARY)
			ft_put_bits_in_tne_list(list);
		if (!(list->string))
		{
			list->flags &= (~BINARY);
			ft_parse_len(list);
			ft_parse_precision(list);
		}
		list = list->next;
	}
}

int		ft_find_latest_arg(s_args *list)
{
	int		biggest;

	biggest = 0;
	while (list)
	{
		if (biggest < list->n_arg_width)
			biggest = list->n_arg_width;
		if (biggest < list->n_arg_precision)
			biggest = list->n_arg_precision;
		if (biggest < list->n_arg)
			biggest = list->n_arg;
		list = list->next;
	}
	return (biggest);
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
			if ((list->type == 'c' || list->type == 's' || list->type == 'p' ||
			list->type == 'd' || list->type == 'i' || list->type == 'o' ||
			list->type == 'u' || list->type == 'x' || list->type == 'X'))
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
	int						last_arg;
	int						cntr;
	char					arg_type;

	first_list = ft_format_string_parse((char*)format);
	last_arg = ft_find_latest_arg(first_list);
	cntr = 1;
	va_start(ap, format);
	while (cntr <= last_arg && (arg_type = ft_slct_type(first_list, cntr)))
	{
		if (arg_type == 'i')
			ft_put(first_list, cntr, va_arg(ap, long int), 0);
		else if (arg_type == 'f')
			ft_put(first_list, cntr, 0, (long double)va_arg(ap, double));
		else if (arg_type == 'F')
			ft_put(first_list, cntr, 0, va_arg(ap, long double));
		else
			ft_errors(ARG_OMITTED);
		cntr++;
	}
	va_end(ap);
	ft_convert_to_string(first_list);

	
	while (first_list)
	{
		printf("\n\"parameter\"         is '%d'\n\n", first_list->order_counter);

		printf("\"n_arg_width\"       is '%d'\n", first_list->n_arg_width);
		printf("\"n_arg_precision\"   is '%d'\n", first_list->n_arg_precision);
		printf("\"n_arg\"             is '%d'\n\n", first_list->n_arg);

		printf("\"width\"             is '%d'\n", first_list->width);
		printf("\"precision\"         is '%d'\n\n", first_list->precision);
		
		printf("\"flags\"             is '%i'\n", first_list->flags);
		printf("\"length\"            is '%c'\n", first_list->length);
		printf("\"type\"              is '%c'\n\n", first_list->type);
		printf("\"int_arg\"           is %lli\n", first_list->int_arg);
		printf("\"float_arg\"         is %Lf\n", first_list->float_arg);
		printf("\"string\"           is \n%s\n", first_list->string);
		printf("------------------------------------\n");


		first_list = first_list->next;
	}


	// ft_clear_the_struct(&first_list);
	return (0);
}