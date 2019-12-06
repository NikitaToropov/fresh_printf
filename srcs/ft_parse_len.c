/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:58 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:27:58 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_types_di_part_two(t_args *list)
{
	if (list->length == SHORT)
	{
		if ((short)list->int_arg < 0 && (list->sign = '-'))
			list->int_arg = ~list->int_arg + 1;
		list->string = ft_itoa_base((unsigned short)list->int_arg, 10);
	}
	else if (list->length == CHAR)
	{
		if ((char)list->int_arg < 0 && (list->sign = '-'))
			list->int_arg = ~list->int_arg + 1;
		list->string = ft_itoa_base((unsigned char)list->int_arg, 10);
	}
	else
	{
		if ((int)list->int_arg < 0 && (list->sign = '-'))
			list->int_arg = ~list->int_arg + 1;
		list->string = ft_itoa_base((unsigned int)list->int_arg, 10);
	}
}

void		ft_parse_types_di(t_args *list)
{
	if (list->length == LONG)
	{
		if ((long int)list->int_arg < 0 && (list->sign = '-'))
			list->int_arg = ~list->int_arg + 1;
		list->string = ft_itoa_base((unsigned long int)list->int_arg, 10);
	}
	else if (list->length == LONG_LONG)
	{
		if ((long long int)list->int_arg < 0 && (list->sign = '-'))
			list->int_arg = ~list->int_arg + 1;
		list->string = ft_itoa_base((unsigned long long int)list->int_arg, 10);
	}
	else
		ft_parse_types_di_part_two(list);
}

void		ft_parse_types_uo(t_args *list)
{
	if (list->type == 'o')
	{
		if (list->length == LONG_LONG)
			list->string = ft_itoa_base((unsigned long long)list->int_arg, 8);
		else if (list->length == LONG)
			list->string = ft_itoa_base((unsigned long int)list->int_arg, 8);
		else if (list->length == CHAR)
			list->string = ft_itoa_base((unsigned char)list->int_arg, 8);
		else if (list->length == SHORT)
			list->string = ft_itoa_base((unsigned short)list->int_arg, 8);
		else
			list->string = ft_itoa_base((unsigned int)list->int_arg, 8);
		return ;
	}
	if (list->length == 'L')
		list->string = ft_itoa_base((unsigned long long)list->int_arg, 10);
	else if (list->length == 'l')
		list->string = ft_itoa_base((unsigned long int)list->int_arg, 10);
	else if (list->length == CHAR)
		list->string = ft_itoa_base((unsigned char)list->int_arg, 10);
	else if (list->length == SHORT)
		list->string = ft_itoa_base((unsigned short)list->int_arg, 10);
	else
		list->string = ft_itoa_base((unsigned int)list->int_arg, 10);
}

void		ft_parse_types_x(t_args *list)
{
	if (list->type == 'x')
	{
		if (list->length == LONG_LONG)
			list->string = ft_itoa_base(list->int_arg, 16);
		else if (list->length == LONG)
			list->string = ft_itoa_base((unsigned long)list->int_arg, 16);
		else if (list->length == CHAR)
			list->string = ft_itoa_base((unsigned char)list->int_arg, 16);
		else if (list->length == SHORT)
			list->string = ft_itoa_base((unsigned short)list->int_arg, 16);
		else
			list->string = ft_itoa_base((unsigned int)list->int_arg, 16);
		return ;
	}
	if (list->length == LONG_LONG)
		list->string = ft_itoa_base_upp(list->int_arg, 16);
	else if (list->length == LONG)
		list->string = ft_itoa_base_upp((unsigned long)list->int_arg, 16);
	else if (list->length == CHAR)
		list->string = ft_itoa_base_upp((unsigned char)list->int_arg, 16);
	else if (list->length == SHORT)
		list->string = ft_itoa_base_upp((unsigned short)list->int_arg, 16);
	else
		list->string = ft_itoa_base_upp((unsigned int)list->int_arg, 16);
}

void		ft_parse_len(t_args *list)
{
	if (list->flags & BINARY && ft_strchr("idfuc", list->type))
		ft_put_bits(list);
	else
	{
		if (list->type == 'f')
			ft_ftoa(list);
		if (list->type == 'd' || list->type == 'i')
			ft_parse_types_di(list);
		if (list->type == 'u' || list->type == 'o')
			ft_parse_types_uo(list);
		if (list->type == 'x' || list->type == 'X')
			ft_parse_types_x(list);
		if (list->type == 'p')
			list->string = ft_itoa_base(list->int_arg, 16);
		if (list->type == 'c')
			list->string = ft_utf8_coder((int)list->int_arg);
		if (list->type == 's')
		{
			if (list->int_arg)
				list->string = ft_strdup((char*)list->int_arg);
			else
				list->string = ft_strdup("(null)");
		}
	}
}
