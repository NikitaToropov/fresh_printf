/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:08 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:28:08 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_convert_args(t_args *list)
{
	while (list)
	{
		ft_parse_len(list);
		if (list->type == 'f')
			ft_precision_f(list);
		if (list->flags & PLUS && ft_strchr("dif", list->type) &&
		!(list->sign))
			list->sign = '+';
		if (list->flags & SPACE && ft_strchr("dif", list->type) &&
		!(list->sign))
			list->sign = ' ';
		if (list->type == 'o' && !(list->int_arg) && list->flags & HASH)
			list->flags &= ~HASH;
		else if (ft_strchr("uxXo", list->type) && !(list->int_arg) &&
		!(list->precision))
			list->string[0] = '\0';
		if (ft_strchr("xX", list->type) && !(list->int_arg))
			list->flags &= ~HASH;
		list->str_len = ft_strlen(list->string);
		list = list->next;
	}
}

int					ft_print_result(char *str, t_args *list)
{
	int				counter;
	char			*tmp;

	counter = 0;
	ft_convert_args(list);
	while (*str)
	{
		if (*str == '%')
		{
			counter += ft_print_arg(list);
			if (*(str = ft_strchr(&str[1], list->type)))
				str++;
			list = list->next;
		}
		else
		{
			if (!list || !(tmp = ft_strchr(str, '%')))
				tmp = ft_strchr(str, '\0');
			write(1, str, (tmp - str));
			counter += tmp - str;
			str = tmp;
		}
	}
	return (counter);
}
