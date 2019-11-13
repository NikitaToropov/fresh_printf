#include "ft_printf.h"

void	ft_precision_dioux(s_args *list, char *str)
{
	unsigned int	old_len;

	list->type &= ~ZERO;
	if ((list->type == 'i' || list->type == 'd') && str[0] == '-')
	{
		old_len = ft_strlen(&str[1]);
		if (old_len < (unsigned int)list->precision)
		{
			ft_shift_right_by(&str[1], (list->precision - old_len));
			ft_fill_by_while(&str[1], '0', (list->precision - old_len));
		}
	}
	else
	{
		old_len = ft_strlen(str);
		if (list->precision == 0 && list->int_arg == 0)
			str[0] = '\0';
		else if (old_len < (unsigned int)list->precision)
		{
			ft_shift_right_by(str, (list->precision - old_len));
			ft_fill_by_while(str, '0', (list->precision - old_len));
		}
	}
}

void	ft_precision_p(s_args *list, char *str)
{
	int		old_len;

	old_len = ft_strlen(str) - 2;
	if (old_len < list->precision)
	{
		ft_shift_right_by(&str[2], (list->precision - old_len));
		ft_fill_by_while(&str[2], '0', (list->precision - old_len));
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
			ft_precision_p(list, str);
	}
}