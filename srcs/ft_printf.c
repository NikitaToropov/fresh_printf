/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:12 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:28:12 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_put_arg(t_args *list, size_t n, unsigned long long i_arg,
long double f_arg)
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
		if (list->num_width == n || list->num_precision == n ||
		(list->num_arg == n && ft_strchr("diouxXcsp", list->type)))
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
	size_t			l;

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
	t_args			*first_list;
	va_list			ap;
	size_t			counter;
	size_t			latest;
	char			type;

	first_list = ft_parse_format(format);
	va_start(ap, format);
	counter = 0;
	latest = ft_find_latest_arg(first_list);
	while (counter++ <= latest)
	{
		if ((type = ft_find_arg_type(first_list, counter)) == 'i')
			ft_put_arg(first_list, counter, va_arg(ap, unsigned long long), 0);
		else if (type == 'f')
			ft_put_arg(first_list, counter, 0, (long double)va_arg(ap, double));
		else if (type == 'F')
			ft_put_arg(first_list, counter, 0, va_arg(ap, long double));
		else
			va_arg(ap, unsigned long long);
	}
	va_end(ap);
	counter = ft_print_result((char*)format, first_list);
	ft_clear_struct(&first_list);
	return (counter);
}
