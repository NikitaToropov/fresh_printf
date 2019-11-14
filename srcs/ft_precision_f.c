#include "ft_printf.h"

void	ft_lengthen_str(t_args *list)
{
	char	*tmp;
	size_t	new_len;

	tmp = list->string;
	new_len = 
	if (!(list->string = ft_memalloc()))
	while 
}


void	ft_add_carry(char *str)
{
	long int		i;
	int				carry;

	i = ft_strlen(str) - 1;
	carry = 1;
	while (i >= 0 && carry && str[i] != '-')
	{
		if (str[i] == '.')
			i--;
		if ((str[i] += 1) > '9')
			str[i] = str[i] - 10;
		else
			carry = 0;
		i--;
	}
	if (carry)
	{
		i = ft_strlen(str);
		while (i >= 0)
		{
			str[i + 1] = str[i];
			i--;
		}
		str[0] = 1;
	}
}

void	ft_precision_f(t_args *list)
{
	int				frac_len;
	char			*frac;

	if (list->precision == -1)
		list->precision = 6;
	if (!(frac = ft_strchr(list->string, '.')))
		return ;
	frac += 1;
	frac_len = ft_strlen(frac);
	if (list->precision < frac_len)
	{
		if (frac[list->precision] < '5')
			frac[list->precision] = '\0';
		else
		{
			frac[list->precision] = '\0';
			ft_add_carry(list->string);
		}
	}
	if (frac_len < list->precision)
		ft_lengthen_str(list, );
	if (list->precision == 0 && !(list->flags & HASH) && frac)
		*(frac - 1) = '\0';
}
