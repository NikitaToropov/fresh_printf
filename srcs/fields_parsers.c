#include "ft_printf.h"

size_t		ft_find_parameter(char *str, t_args *list)
{
	char	*tmp_str;

	if (*str == '0')
		return (0);
	tmp_str = str;
	while (*tmp_str >= '0' && *tmp_str <= '9')
		tmp_str++;
	if (*tmp_str == '$' && tmp_str != str)
	{
		list->order_counter = ft_atoi(str);
		return (tmp_str - str + 1);
	}
	return (0);
}

size_t		ft_find_flag(char c, t_args *list)
{
	if (c == '#')
		list->flags |= HASH;
	else if (c == '0')
		list->flags |= ZERO;
	else if (c == '-')
		list->flags |= MINUS;
	else if (c == ' ')
		list->flags |= SPACE;
	else if (c == '+')
		list->flags |= PLUS;
	else if (c == '\'')
		list->flags |= APOSTROPHE;
	else if (c == 'b')
		list->flags |= BINARY;
	if (list->flags & MINUS)
		list->flags &= (~ZERO);
	if (list->flags & PLUS)
		list->flags &= (~SPACE);
	if (c && ft_strchr("b#0-+' ", c))
		return (1);
	return (0);
}

size_t		ft_find_width(char *str, t_args *list)
{
	char	*tmp_str;

	if (str[0] == '*')
	{
		if ((str[1] >= '1' && str[1] <= '9') && str[2] == '$')
		{
			list->num_width = (int)(str[1] - '0');
			return (3);
		}
		else
		{
			list->num_width = list->order_counter;
			list->order_counter += 1;
			return (1);
		}
	}
	tmp_str = str;
	while (*tmp_str >= '0' && *tmp_str <= '9' && *str != '0')
		tmp_str++;
	if (tmp_str != str)
	{
		list->width = ft_atoi(str);
		list->num_width = 0;
	}
	return (tmp_str - str);
}

size_t		ft_find_precision(char *str, t_args *list)
{
	char	*tmp_str;
	if (str[0] == '.')
	{
		if (str[1] == '*' && (str[2] >= '0' || str[2] <= '9') && str[3] == '$')
		{
			(list->num_precision = str[2] - '0');
			return (4);
		}
		if (str[1] == '*')
		{
			list->num_precision = list->order_counter;
			list->order_counter += 1;
			return (2);
		}
		list->num_precision = 0;
		tmp_str = &str[1];
		while (*tmp_str >= '0' && *tmp_str <= '9')
			tmp_str++;
		list->precision = ft_atoi(&str[1]);
		return (tmp_str - str);
	}
	return (0);
}

size_t		ft_find_length(char *str, t_args *list)
{
	if ((str[0] == 'h' && str[1] == 'h') || (str[0] == 'l' && str[1] == 'l'))
	{
		if (str[0] == 'h')
			list->length = CHAR;
		else
			list->length = LONG_LONG;
		return (2);
	}
	else if (str[0] == 'h' || str[0] == 'l' || str[0] == 'L')
	{
		if (str[0] == 'h')
			list->length = SHORT;
		else if (str[0] == 'l')
			list->length = LONG;
		else
			list->length = LONG_DOUBLE;
		return (1);
	}
	return (0);
}
