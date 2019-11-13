#include "ft_printf.h"

static void			ft_put_arg(t_args *list, size_t n, unsigned long long i_arg, long double f_arg)
{
	while (list)
	{
		if (list->num_width == n)
			list->width = (int)i_arg;
		if (list->num_precision == n)
			list->precision = (int)i_arg;
		if (list->num_arg == n)
		{
			if (list->type == 'f')
				list->float_arg = f_arg;
			else
				list->int_arg = i_arg;
		}
		list = list->next;
	}
}

static char			ft_find_arg_type(t_args *list, size_t n)
{
	while (list)
	{
		if (list->num_width == n || list->num_width == n ||
		(list->num_arg = n && ft_strchr("diouxXcsp", list->type)))
			return ('i');
		else if (list->num_arg == n && list->type == 'f' && list->length == 'D')
			return ('F');
		else if (list->num_arg == n && list->type == 'f')
			return ('f');
		list = list->next;
	}
	return ('E');
}

static size_t		ft_find_latest_arg(t_args *list)
{
	size_t		l;

	l = 0;
	while (list)
	{
		if (list->num_arg > l) 
			l = list->num_arg;
		if (list->num_precision > l)
			l = list->num_precision;
		if (list->num_width > l)
			l = list->num_width;
		list = list->next;
	}
	return (l);
}

int					ft_printf(const char *format, ...)
{
	t_args					*first_list;
	va_list					ap;
	size_t					counter;
	size_t					latest;
	char					type;

	first_list = ft_parse_format(format);
	va_start(ap, format);
	counter = 1;
	latest = ft_find_latest_arg(first_list);
	while (counter <= latest)
	{
		if ((type = ft_find_arg_type(first_list, counter)) == 'i')
			ft_put_arg(first_list, counter, va_arg(ap, unsigned long long), 0);
		else if (type == 'f')
			ft_put_arg(first_list, counter, 0, (long double)va_arg(ap, double));
		else if (type == 'F')
			ft_put_arg(first_list, counter, 0, va_arg(ap, long double));
		else
			va_arg(ap, unsigned long long);
		counter++;
	}
	va_end(ap);
	// while (first_list)
	// {
	// 	printf("\n\"order_counter\"   is '%zu'\n\n", first_list->order_counter);

	// 	printf("\"num_width\"         is '%zu'\n", first_list->num_width);
	// 	printf("\"num_precision\"     is '%zu'\n", first_list->num_precision);
	// 	printf("\"num_arg\"           is '%zu'\n\n", first_list->num_arg);

	// 	printf("\"width\"             is '%i'\n", first_list->width);
	// 	printf("\"precision\"         is '%i'\n\n", first_list->precision);
		
	// 	printf("\"flags\"             is '%i'\n", first_list->flags);
	// 	printf("\"length\"            is '%c'\n", first_list->length);
	// 	printf("\"type\"              is '%c'\n\n", first_list->type);
		
	// 	printf("\"string\"            is '%s'\n", first_list->string);
	// 	printf("\"str_len\"            is '%zu'\n", first_list->str_len);
	// 	printf("\"sign\"              is '%c'\n", first_list->sign);
	// 	printf("\"pass_start\"        is '%zu'\n", first_list->pass_start);
	// 	printf("\"pass_length\"       is '%zu'\n", first_list->pass_length);
		

	// 	printf("------------------------------------\n");


	// 	first_list = first_list->next;
	// }
	return (ft_print_result(&first_list));
}
