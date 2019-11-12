#include "ft_printf.h"

void	ft_precision_dioux(s_args *list, char *str)
{
	unsigned int	old_len;

	old_len = ft_strlen(str);
	if (list->precision == 0 && list->int_arg == 0)
		str[0] = '0';
	else if (old_len < (unsigned int)list->precision)
	{
		ft_shift_right_by(str, (list->precision - old_len));
		ft_fill_by_while(str, '0', (list->precision - old_len));
	}
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

void	ft_parse_precision(s_args *list, char *str)
{
	if (list->type == 'f')
		ft_precision_f(list, str);
	else if (list->type == 's' && list->precision != -1 &&
	((int)ft_strlen(list->string) > list->precision))
		str[list->precision] = '\0';
	else if (list->precision != -1)
	{
		if (list->type == 'd' || list->type == 'i' || list->type == 'o' ||
		list->type == 'x' || list->type == 'X' || list->type == 'u')
			ft_precision_dioux(list, str);
		else if (list->type == 'p')
			ft_precision_p(list);
	}
}