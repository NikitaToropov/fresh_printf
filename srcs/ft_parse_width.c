#include "ft_printf.h"

void	ft_parse_width(s_args *list, char *str)
{
	unsigned int	old_len;

	old_len = ft_strlen(str);
	if ((unsigned int)list->width > old_len)
	{
		if (list->flags & MINUS)
			ft_fill_by_while(&str[old_len - 1], ' ', list->width - old_len);
		else if (list->flags & ZERO)
		{
			if (str[0] == '-' || str[0] == '+')
			{
				ft_shift_right_by(&str[1], list->width - old_len);
				ft_fill_by_while(&str[1], '0', (list->width - old_len));
			}
			else
			{
				ft_shift_right_by(str, list->width - old_len);
				ft_fill_by_while(str, '0', list->width - old_len);
			}
		}
		else
		{
			if (str[0] == '-' || str[0] == '+')
			{
				ft_shift_right_by(&str[1], list->width - old_len);
				ft_fill_by_while(&str[1], '0', (list->width - old_len));
			}
			else
			{
				ft_shift_right_by(str, list->width - old_len);
				ft_fill_by_while(str, ' ', list->width - old_len);
			}
			
		}
	}
}