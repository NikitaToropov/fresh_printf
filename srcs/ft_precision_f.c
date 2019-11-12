#include "ft_printf.h"

int		ft_add_carry(char *str)
{
	long int		countdown;
	int				carry;

	countdown = ft_strlen(str) - 1;
	carry = 1;
	while (countdown >= 0 && carry && str[countdown] != '-')
	{
		if (str[countdown] == '.')
			countdown--;
		if ((str[countdown] += 1) > '9')
			str[countdown] = str[countdown] - 10;
		else
			carry = 0;
		countdown--;
	}
	return (carry);
}

void	ft_fill_with_carry(char *str)
{
	if (ft_add_carry(str))
	{
		if (str[0] == '-')
		{
			ft_shift_right_by(&str[1], 1);
			str[1] = 1;
		}
		else
		{
			ft_shift_right_by(str, 1);
			str[0] = 1;
		}
	}
}

void	ft_accuracy_reduction(s_args *list, char *str, char *dot)
{
	int		carry;

	carry = 0;
	if ((list->precision && dot[list->precision + 1] >= '5') ||
	(!(list->precision) && dot[1] >= '5'))
		carry = 1;
	dot[list->precision + 1] = '\0';
	if (carry)
		ft_fill_with_carry(str);
	if (!(list->flags & HASH) && !(list->precision))
	{
		dot = ft_strchr(str, '.');
		*dot = '\0';
	}
}

void	ft_precision_f(s_args *list, char *str)
{
	char	*dot;
	int		old_prec;

	if (list->precision == -1)
		list->precision = 6;
	dot = ft_strchr(str, '.');
	old_prec = ft_strlen(dot) - 1;
	if (old_prec < list->precision)
	{
		ft_fill_by_while(&dot[old_prec + 1], '0', (list->precision - old_prec));
		dot[list->precision + 1] = '\0';
	}
	else if (old_prec > list->precision)
		ft_accuracy_reduction(list, str, dot);
}
