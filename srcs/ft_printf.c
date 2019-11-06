#include "ft_printf.h"

int		ft_arg_is_integer(char type)
{
	if (type == 'c' || type == 's' || type == 'p' ||
	type == 'd' || type == 'i' || type == 'o' ||
	type == 'u' || type == 'x' || type == 'X')
		return (1);
	return (0);
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

char	ft_select_argument_type(s_args *list, int counter_arg)
{
	while (list)
	{
		if (list->n_arg_width == counter_arg ||
		list->n_arg_precision == counter_arg ||
		(list->n_arg == counter_arg && ft_arg_is_integer(list->type)))
			return ('i');
		if (list->n_arg == counter_arg && list->type == 'f' &&
		list->length != 'F')
			return ('f');
		if (list->n_arg == counter_arg && list->type == 'f' &&
		list->length == 'F')
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
			if (ft_arg_is_integer(list->type))
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
	int						latest_arg;
	int						counter_arg;
	char					type_selector;

	first_list = ft_format_string_parse((char*)format);
	va_start(ap, format);
	latest_arg = ft_find_latest_arg(first_list);
	counter_arg = 1;
	while (counter_arg <= latest_arg)
	{
		type_selector = ft_select_argument_type(first_list, counter_arg);
		if (type_selector == 'i')
			ft_put(first_list, counter_arg, va_arg(ap, long int), 0);
		else if (type_selector == 'f')
			ft_put(first_list, counter_arg, 0, (long double)va_arg(ap, double));
		else if (type_selector == 'F')
			ft_put(first_list, counter_arg, 0, va_arg(ap, long double));
		else
		{
			printf("%i\n", counter_arg);
			ft_errors(ARG_OMITTED);
		}
		counter_arg++;
	}
	va_end(ap);

	
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
		printf("------------------------------------\n");


		first_list = first_list->next;
	}


	// ft_clear_the_struct(&first_list);
	return (0);
}