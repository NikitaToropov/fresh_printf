#include "ft_printf.h"

void	ft_lengthen_str(t_args *list, int frac_len)
{
	char	*tmp;
	int		new_len;
	int		old_len;
	int		i;

	old_len = ft_strlen(list->string);
	new_len = old_len - frac_len + list->precision;
	tmp = list->string;
	if (!(list->string = ft_memalloc(new_len + 1)))
		exit(1);
	i = 0;
	while (i < new_len)
	{
		if (i < old_len)
			list->string[i] = tmp[i];
		else
			list->string[i] = '0';
		i++;
	}
	free(tmp);
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
		ft_lengthen_str(list, frac_len);
	if (list->precision == 0 && !(list->flags & HASH) && frac)
		*(frac - 1) = '\0';
}
