#include "ft_printf.h"

void	ft_parse_types_di(s_args *list, unsigned long long argument)
{
	
	if (list->length == 'l')
		list->arg = ft_itoa((long int)argument);
	else if (list->length == 'L')
		list->arg = ft_itoa((long long int)argument);
	else if (list->length == 'h')
		list->arg = ft_itoa((short)argument);
	else if (list->length == 'H')
		list->arg = ft_itoa((char)argument);
	else
		list->arg = ft_itoa((int)argument);
}

void	ft_parse_types_uo(s_args *list, unsigned long long argument)
{
	if (list->type == 'o')
	{
		if (list->length == 'L')
			list->arg = ft_itoa_base((unsigned long long)argument, 8);
		else if (list->length == 'l')
			list->arg = ft_itoa_base((unsigned long int)argument, 8);
		else if (list->length == 'H')
			list->arg = ft_itoa_base((unsigned char)argument, 8);
		else if (list->length == 'h')
			list->arg = ft_itoa_base((unsigned short)argument, 8);
		else
			list->arg = ft_itoa_base((unsigned int)argument, 8);
	}
	else
	{
		if (list->length == 'L')
			list->arg = ft_itoa_base((unsigned long long)argument, 10);
		else if (list->length == 'l')
			list->arg = ft_itoa_base((unsigned long int)argument, 10);
		else if (list->length == 'H')
			list->arg = ft_itoa_base((unsigned char)argument, 10);
		else if (list->length == 'h')
			list->arg = ft_itoa_base((unsigned short)argument, 10);
		else
			list->arg = ft_itoa_base((unsigned int)argument, 10);
	}
}

void	ft_parse_types_xXp(s_args *list, unsigned long long argument)
{
	if (list->type == 'x')
	{
		if (list->length == 'L')
			list->arg = ft_itoa_base(argument, 16);
		else if (list->length == 'l')
			list->arg = ft_itoa_base((unsigned long)argument, 16);
		else if (list->length == 'H')
			list->arg = ft_itoa_base((unsigned char)argument, 16);
		else if (list->length == 'h')
			list->arg = ft_itoa_base((unsigned short)argument, 16);
		else
			list->arg = ft_itoa_base((unsigned int)argument, 16);
	}
	else if (list->type == 'X')
	{
		if (list->length == 'L')
			list->arg = ft_itoa_base_uppercase(argument, 16);
		else if (list->length == 'l')
			list->arg = ft_itoa_base_uppercase((unsigned long)argument, 16);
		else if (list->length == 'H')
			list->arg = ft_itoa_base_uppercase((unsigned char)argument, 16);
		else if (list->length == 'h')
			list->arg = ft_itoa_base_uppercase((unsigned short)argument, 16);
		else
			list->arg = ft_itoa_base_uppercase((unsigned int)argument, 16);
	}
	else
		list->arg = ft_itoa_pointer(argument);
}

void	ft_put_integer_arg(s_args *list, unsigned long long argument)
{
	if (list->type == 'd' || list->type == 'i')
		ft_parse_types_di(list, argument);
	if (list->type == 'u' || list->type == 'o')
		ft_parse_types_uo(list, argument);
	if (list->type == 'x' || list->type == 'X' || list->type == 'p')
		ft_parse_types_xXp(list, argument);
	if (list->type == 'c')
		list->arg = ft_utf_8_coder((int)argument);
	if (list->type == 's')
		list->arg = ft_strdup((char*)argument);
}