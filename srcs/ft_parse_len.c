#include "ft_printf.h"

void	ft_parse_types_di(t_args *list)
{
	if (list->length == 'l')
	{
		if ((long int)list->int_arg < 0 && (list->sign = '-'))
			list->string = ft_itoa_base((long int)list->int_arg * (-1), 10);
		else
			list->string = ft_itoa_base((long int)list->int_arg, 10);
	}
	else if (list->length == 'L')
	{
		if ((long long int)list->int_arg < 0 && (list->sign = '-'))
			list->string = ft_itoa_base((long long int)list->int_arg * (-1), 10);
		else
			list->string = ft_itoa_base((long long int)list->int_arg, 10);
	}
	else if (list->length == 'h')
	{
		if ((short)list->int_arg < 0 && (list->sign = '-'))
			list->string = ft_itoa_base((short)list->int_arg * (-1), 10);
		else
			list->string = ft_itoa_base((short)list->int_arg, 10);
	}
	else if (list->length == 'H')
	{
		if ((char)list->int_arg < 0 && (list->sign = '-'))
			list->string = ft_itoa_base((char)list->int_arg * (-1), 10);
		else
			list->string = ft_itoa_base((char)list->int_arg, 10);
	}
	else
	{
		if ((int)list->int_arg < 0 && (list->sign = '-'))
			list->string = ft_itoa_base((int)list->int_arg * (-1), 10);
		else
			list->string = ft_itoa_base((int)list->int_arg, 10);
	}
}

void	ft_parse_types_uo(t_args *list)
{
	if (list->type == 'o')
	{
		if (list->length == 'L')
			list->string = ft_itoa_base((unsigned long long)list->int_arg, 8);
		else if (list->length == 'l')
			list->string = ft_itoa_base((unsigned long int)list->int_arg, 8);
		else if (list->length == 'H')
			list->string = ft_itoa_base((unsigned char)list->int_arg, 8);
		else if (list->length == 'h')
			list->string = ft_itoa_base((unsigned short)list->int_arg, 8);
		else
			list->string = ft_itoa_base((unsigned int)list->int_arg, 8);
		return ;
	}
	if (list->length == 'L')
		list->string = ft_itoa_base((unsigned long long)list->int_arg, 10);
	else if (list->length == 'l')
		list->string = ft_itoa_base((unsigned long int)list->int_arg, 10);
	else if (list->length == 'H')
		list->string = ft_itoa_base((unsigned char)list->int_arg, 10);
	else if (list->length == 'h')
		list->string = ft_itoa_base((unsigned short)list->int_arg, 10);
	else
		list->string = ft_itoa_base((unsigned int)list->int_arg, 10);
}

void		ft_parse_types_x(t_args *list)
{
	if (list->type == 'x')
	{
		if (list->length == 'L')
			list->string = ft_itoa_base(list->int_arg, 16);
		else if (list->length == 'l')
			list->string = ft_itoa_base((unsigned long)list->int_arg, 16);
		else if (list->length == 'H')
			list->string = ft_itoa_base((unsigned char)list->int_arg, 16);
		else if (list->length == 'h')
			list->string = ft_itoa_base((unsigned short)list->int_arg, 16);
		else
			list->string = ft_itoa_base((unsigned int)list->int_arg, 16);
		return ;
	}
	if (list->length == 'L')
		list->string = ft_itoa_base_upp(list->int_arg, 16);
	else if (list->length == 'l')
		list->string = ft_itoa_base_upp((unsigned long)list->int_arg, 16);
	else if (list->length == 'H')
		list->string = ft_itoa_base_upp((unsigned char)list->int_arg, 16);
	else if (list->length == 'h')
		list->string = ft_itoa_base_upp((unsigned short)list->int_arg, 16);
	else
		list->string = ft_itoa_base_upp((unsigned int)list->int_arg, 16);
}

void	ft_parse_len(t_args *list)
{
	if (list->type == 'f')
		ft_ftoa(list);
	if (list->type == 'd' || list->type == 'i')
		ft_parse_types_di(list);
	if (list->type == 'u' || list->type == 'o')
		ft_parse_types_uo(list);
	if (list->type == 'x' || list->type == 'X' || list->type == 'p')
		ft_parse_types_x(list);
	if (list->type == 'p')
		list->string = ft_itoa_pointer(list->int_arg);
	if (list->type == 'c')
		list->string = ft_utf8_coder((int)list->int_arg);
	if (list->type == 's')
		list->string = ft_strdup((char*)list->int_arg);
}