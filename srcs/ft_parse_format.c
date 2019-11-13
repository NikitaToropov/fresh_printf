#include "ft_printf.h"

static void	ft_analise_the_fields(t_args *list, size_t *i)
{
	if (list->type)
	{
		list->num_arg = list->order_counter;
		list->order_counter++;
		list->pass_length = *i - list->pass_start + 1;
		(*i)++;
	}
	else if (list->str_len)
	{
		list->pass_length = *i - list->pass_start + 1;
		(*i)++;
	}
	else
		list->pass_length = *i - list->pass_start;
}

static void		ft_parse_inner(const char *str, t_args *list, size_t *i)
{
	size_t		tmp;

	list->pass_start = (*i)++;
	while (str[*i] && tmp != *i)
	{
		tmp = *i;
		*i += ft_find_parameter((char*)&str[*i], list);
		*i += ft_find_flag((char)str[*i], list);
		*i += ft_find_width((char*)&str[*i], list);
		*i += ft_find_precision((char*)&str[*i], list);
		*i += ft_find_length((char*)&str[*i], list);
	}
	if (str[*i] && ft_strchr("diouxXfcsp", str[*i]))
		list->type = str[*i];
	else
	{
		if (!(list->string = ft_memalloc(2)))
			exit(1);
		list->string[0] = str[*i];
		list->str_len = ft_strlen(list->string);
	}
	ft_analise_the_fields(list, i);
}

static t_args	*ft_make_list(size_t counter)
{
	t_args			*list;

	if (!(list = malloc(sizeof(t_args))))
		exit(1);
	list->order_counter = counter;

	list->num_width = 0;
	list->num_precision = 0;
	list->num_arg = 0;

	list->width = -1;
	list->precision = -1;

	list->int_arg = 0;
	list->float_arg = 0;
	
	list->flags = 0;
	list->length = 0;
	list->type = 0;

	list->string = NULL;
	list->str_len = 0;
	list->sign = 0;
	list->pass_length = 0;
	list->next = NULL;
	return (list);
}

t_args			*ft_parse_format(const char *str)
{
	size_t		i;
	t_args		*first_list;
	t_args		*list;

	i = 0;
	first_list = NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!first_list && (first_list = ft_make_list(1)))
				list = first_list;
			else if ((list->next = ft_make_list(list->order_counter)))
				list = list->next;
			ft_parse_inner(str, list, &i);
		}
		else
		{
			while (str[i] && str[i] != '%')
				i++;
		}
	}
	return (first_list);
}
