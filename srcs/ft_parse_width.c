#include "ft_printf.h"

void	ft_zero_flag_width(s_args *list, int old)
{
	char	*tmp;
	int		new;
	int		minus;

	tmp = list->string;
	if (!(list->string = (char*)malloc(sizeof(char) * (list->width + 1))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->string[list->width] = '\0';
	new = list->width - 1;
	minus = 0;
	while (new >= 0)
	{
		if ((list->type == 'p' && (old > 1 || old == new)) ||
		(list->type != 'p' && old >= 0 && tmp[old] != '-' && tmp[old] != '+'))
			list->string[new--] = tmp[old--];
		else
			list->string[new--] = '0';
	}
	if (tmp[0] == '-' || tmp[0] == '+')
		list->string[0] = tmp[0];
	free(tmp);
}

void	ft_minus_flag_width(s_args *list, int old)
{
	char	*tmp;
	int		new;

	tmp = list->string;
	if (!(list->string = (char*)malloc(sizeof(char) * (list->width + 1))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->string[list->width] = '\0';
	new = list->width - 1;
	while (new >= 0)
	{
		if (old == new)
			list->string[new--] = tmp[old--];
		else
			list->string[new--] = ' ';
	}
	free(tmp);
}

void	ft_width(s_args *list, int old)
{
	char	*tmp;
	int		new;

	tmp = list->string;
	if (!(list->string = (char*)malloc(sizeof(char) * (list->width + 1))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->string[list->width] = '\0';
	new = list->width - 1;
	while (new >= 0)
	{
		if (old >= 0)
			list->string[new--] = tmp[old--];
		else
			list->string[new--] = ' ';
	}
	free(tmp);
}

void	ft_parse_width(s_args *list)
{
	int		old_len;

	old_len = ft_strlen(list->string);
	if (old_len < list->width)
	{
		if (list->flags & MINUS)
			ft_minus_flag_width(list, old_len - 1);
		else if (list->flags & ZERO && (list->type == 'p'
		|| list->type == 'f' || list->type == 'i' || list->type == 'd' ||
		list->type == 'o' || list->type == 'u' || list->type == 'x' ||
		list->type == 'X'))
			ft_zero_flag_width(list, old_len - 1);
		else
			ft_width(list, old_len - 1);
	}
}
