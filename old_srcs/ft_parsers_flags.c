#include "ft_printf.h"

void	ft_parse_flag_h(s_args *list, char *str)
{
	if (list->flags & HASH)
	{
		if (list->type == 'o')
		{
			ft_shift_right_by(str, 1);
			str[0] = '0';
		}
		if (list->type == 'x')
		{
			ft_shift_right_by(str, 2);
			str[0] = '0';
			str[1] = 'x';
		}
		if (list->type == 'X')
		{
			ft_shift_right_by(str, 2);
			str[0] = '0';
			str[1] = 'X';
		}
	}
}

void	ft_parse_flag_ps(s_args *list, char *str)
{
	if ((list->type == 'd' || list->type == 'i' || list->type == 'f') &&
	(list->flags & PLUS || list->flags & SPACE) && *str != '-')
	{
		ft_shift_right_by(str, 1);
		if (list->flags & PLUS)
			str[0] = '+';
		else
			str[0] = ' ';
	}
}