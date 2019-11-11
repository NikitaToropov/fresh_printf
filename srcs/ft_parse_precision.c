#include "ft_printf.h"

void	ft_precision_dioux(s_args *list)
{
	int		old;
	int		new;
	char	*tmp;

	old = ft_strlen(list->string);
	new = list->precision;
	if (list->string[0] == '-' || list->string[0] == '+')
		new++;
	if (new > old)
	{
		tmp = list->string;
		if (!(list->string = (char*)malloc(sizeof(char) * (new + 1))))
			ft_errors(MEM_IS_NOT_ALLOC);
		while (new >= 0)
		{
			if (old >= 0 && tmp[old] != '-')
				list->string[new--] = tmp[old--];
			else
				list->string[new--] = '0';
		}
		if (tmp[0] == '-' || tmp[0] == '+')
			list->string[0] = tmp[0];
		free(tmp);
	}
	if (list->precision == 0 && list->int_arg == 0)
		list->string[0] = '\0';
}

void	ft_precision_p(s_args *list)
{
	int		old;
	int		new;
	char	*tmp;

	old = ft_strlen(list->string);
	new = list->precision + 2;
	if (new > old)
	{
		tmp = list->string;
		if (!(list->string = (char*)malloc(sizeof(char) * (new + 1))))
			ft_errors(MEM_IS_NOT_ALLOC);
		while (new >= 0)
		{
			if (list->type == 'p' && (old > 1 || old == new))
				list->string[new--] = tmp[old--];
			else
				list->string[new--] = '0';
		}
		free(tmp);
	}
}

void	ft_parse_precision(s_args *list)
{
	if (list->flags & BINARY)
		return ;
	if (list->type == 'f')
		ft_precision_f(list);
	else if (list->type == 's' && list->precision != -1 &&
	ft_strlen(list->string) > list->precision)
		list->string[list->precision] = '\0';
	else if (list->precision != -1)
	{
		list->flags &= ~ZERO;
		if (list->type == 'd' || list->type == 'i' || list->type == 'o' ||
		list->type == 'x' || list->type == 'X' || list->type == 'u')
			ft_precision_dioux(list);
		else if (list->type == 'p')
			ft_precision_p(list);
	}
}
