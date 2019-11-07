#include "ft_printf.h"

void	ft_precision_diouxp(s_args *list)
{
	int		old;
	int		new;
	char	*tmp;

	old = ft_strlen(list->string);
	if (list->type == 'p')
		new = list->precision + 2;
	else
		new = list->precision;
	if (new > old)
	{
		tmp = list->string;
		if (!(list->string = (char*)malloc(sizeof(char) * (new + 1))))
			ft_errors(MEM_IS_NOT_ALLOC);
		while (new >= 0)
		{
			if ((list->type == 'p' && (old > 1 || old == new)) ||
			(list->type != 'p' && old >= 0))
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
	else if (list->precision != -1 && (list->type == 'd' ||
	list->type == 'i' || list->type == 'o' || list->type == 'x' ||
	list->type == 'X' || list->type == 'u' || list->type == 'p'))
		ft_precision_diouxp(list);
}
