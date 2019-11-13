#include "ft_printf.h"

void	ft_convert_to_string(s_args *list)
{
	while (list)
	{
		if (list->flags & BINARY)
			ft_put_bits_in_tne_list(list);
		if (list->type != '%' && !(list->string))
			ft_parse_len(list);
		else
			list->string = ft_strdup("%");
		list = list->next;
	}
}
