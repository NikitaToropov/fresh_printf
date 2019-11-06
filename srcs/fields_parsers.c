#include "ft_printf.h"

int		ft_find_parameter(char *str, s_args *list)
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

int		ft_find_flag(char symbol, s_args *list)
{
	if (symbol == '#')
		list->flags |= HASH;
	else if (symbol == '0')
		list->flags |= ZERO;
	else if (symbol == '-')
		list->flags |= MINUS;
	else if (symbol == ' ')
		list->flags |= SPACE;
	else if (symbol == '+')
		list->flags |= PLUS;
	else if (symbol == '\'')
		list->flags |= APOSTROPHE;
	else if (symbol == 'b')
		list->flags |= BINARY;
	if (list->flags & MINUS)
		list->flags &= (~ZERO);
	if (list->flags & PLUS)
		list->flags &= (~SPACE);
	if (symbol == '#' || symbol == '0' ||
	symbol == '-' || symbol == ' ' ||
	symbol == '+' || symbol == '\'' ||
	symbol == 'b')
		return (1);
	return (0);
}

int		ft_find_width(char *str, s_args *list)
{
	char	*tmp_str;

	if (str[0] == '*')
	{
		if ((str[1] >= '1' && str[1] <= '9') && str[2] == '$')
		{
			list->n_arg_width = (int)(str[1] - '0');
			return (3);
		}
		else
		{
			list->n_arg_width = list->order_counter;
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
		list->n_arg_width = 0;
	}
	return (tmp_str - str);
}

int		ft_find_precision(char *str, s_args *list)
{
	char	*tmp_str;

	if (str[0] == '.' && str[1] == '*' && (str[2] >= '0' || str[2] <= '9') &&
	str[3] == '$' && (list->n_arg_precision = str[2] - '0'))
		return (4);
	if (str[0] == '.' && (str[1] == '0' || str[1] == '*'))
	{
		if (str[1] == '*' && (list->n_arg_precision = list->order_counter))
			list->order_counter += 1;
		else
		{
			list->n_arg_precision = 0;
			list->precision = 0;
		}
		return (2);
	}
	if (str[0] == '.' && str[1] >= '1' && str[1] <= '9' && (tmp_str = &str[1]))
	{
		list->n_arg_precision = 0;
		while (*tmp_str >= '0' && *tmp_str <= '9')
			tmp_str++;
		list->precision = ft_atoi(&str[1]);
		return (tmp_str - str);
	}
	return (0);
}

int		ft_find_length(char *str, s_args *list)
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
