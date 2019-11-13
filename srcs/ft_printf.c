#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_args					*first_list;
	// va_list					ap;

	first_list = ft_parse_format(format);
	// va_start(ap, format);
	// va_end(ap);
	while (first_list)
	{
		printf("\n\"order_counter\"   is '%zu'\n\n", first_list->order_counter);

		printf("\"num_width\"         is '%zu'\n", first_list->num_width);
		printf("\"num_precision\"     is '%zu'\n", first_list->num_precision);
		printf("\"num_arg\"           is '%zu'\n\n", first_list->num_arg);

		printf("\"width\"             is '%i'\n", first_list->width);
		printf("\"precision\"         is '%i'\n\n", first_list->precision);
		
		printf("\"flags\"             is '%i'\n", first_list->flags);
		printf("\"length\"            is '%c'\n", first_list->length);
		printf("\"type\"              is '%c'\n\n", first_list->type);
		
		printf("\"string\"            is '%s'\n", first_list->string);
		printf("\"str_len\"            is '%zu'\n", first_list->str_len);
		printf("\"sign\"              is '%c'\n", first_list->sign);
		printf("\"pass_start\"        is '%zu'\n", first_list->pass_start);
		printf("\"pass_length\"       is '%zu'\n", first_list->pass_length);
		

		printf("------------------------------------\n");


		first_list = first_list->next;
	}
	return (1);
}
