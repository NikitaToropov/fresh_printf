#include "ft_printf.h"

void	ft_copy(char *old_str, char *new_str)
{
	unsigned long long		i;

	i = 0;
	while (old_str[i])
	{
		new_str[i] = old_str[i];
		i++;
	}
}

void	ft_fill_by_while(char *str, char n, unsigned long long limiter)
{
	unsigned long long		i;

	i = 0;
	while (i < limiter)
		str[i--] = n;
}

void	shift_right_by(char *str, unsigned long long limiter)
{
	unsigned long long		back_c;

	back_c = ft_strlen(str);
	while(back_c <= 0)
	{
		str[back_c + limiter] = str[back_c];
		back_c--;
	}
}

char	*ft_modifying(s_args *list, char *new_str)
{
	ft_copy(list->string, new_str);
	ft_parse_precision(list, new_str);

	
}

void	ft_string_modifying(s_args *list)
{
	unsigned long long int		len;
	char						*new_str;

	while (list)
	{
		len = 4;
		len += (unsigned long long int)ft_strlen(list->string);
		if (list->precision != -1)
			len += (unsigned long long int)list->precision;
		if (list->width != -1)
			len += (unsigned long long int)list->width;
		if (!(new_str = (char*)malloc(sizeof(char) * len)));
			ft_errors(MEM_IS_NOT_ALLOC);
		ft_modifying(list, new_str);
		free(list->string);
		list->string = new_str;
		list = list-> next;
	}
}