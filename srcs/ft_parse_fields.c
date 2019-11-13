#include "ft_printf.h"

void	ft_parse_fields(const char *str, t_args *list)
{
	size_t		c;
	size_t		end;

	c = list->pass_start + 1;
	end = list->pass_start + list->pass_length;
	while (c < end)
	{
		c += ft_find_parameter(&str[c], list);
		c += ft_find_flag(str[c], list);
		c += ft_find_width(&str[c], list);
		c += ft_find_width(&str[c], list);

	}
}