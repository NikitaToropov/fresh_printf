#include "ft_printf.h"

char	*ft_modifying_in_stack(s_args *list, unsigned long long len)
{
	char	new_str[len];
}

void	ft_string_modifying(s_args *list)
{
	unsigned long long int		len;
	char						*new_str;

	while (list)
	{
		len = 0;
		len += ft_strlen(list->string);
		if (list->precision != -1)
			len += list->precision;
		if (list->width != -1)
			len += list->width;
		len += 4;
		new = ft_modifying_in_stack(list, len);
		list = list-> next;
	}
}