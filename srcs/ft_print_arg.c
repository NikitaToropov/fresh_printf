#include "ft_printf.h"

void	ft_analise_dif(t_args *list, int *n_zeros, int *n_spaces)
{
	int		i;

	i = list->str_len;
	if (list->precision != -1 && list->type != 'f')
		list->flags &= ~ZERO;
	if (!(list->precision) && list->type != 'f' && !(list->int_arg))
	{
		list->string[0]= '\0';
		list->str_len= 0;
	}
	if (list->precision > (int)list->str_len && list->type != 'f')
		*n_zeros += list->precision - list->str_len;
	i += *n_zeros;
	if (list->sign)
		i++;
	if (list->width > i && list->flags & ZERO)
		*n_zeros += list->width - i;
	else if (list->width > i)
		*n_spaces += list->width - i;
}

void	ft_analise_oux(t_args *list, int *n_zeros, int *n_spaces)
{
	int		i;

	i = list->str_len;
	if (list->precision != -1)
		list->flags &= ~ZERO;
	if (list->precision > (int)list->str_len)
		*n_zeros += list->precision - list->str_len;
	i += *n_zeros;
	if (list->flags & HASH && (i += 1))
		list->sign = '0';
	if (list->width > i && list->flags & ZERO)
		*n_zeros += list->width - i;
	else if (list->width > i)
		*n_spaces += list->width - i;
}

void	ft_analise_cs(t_args *list, int *n_zeros, int *n_spaces)
{
	int		i;
	
	if (list->precision != -1 && list->precision < (int)list->str_len)
		list->str_len = list->precision;
	i = list->str_len;
	if (list->width > i && list->flags & ZERO)
		*n_zeros += list->width - i;
	else if (list->width > i)
		*n_spaces += list->width - i;
}

int		ft_write_all(t_args *list, int n_zeros, int n_spaces)
{
	int		counter;
	
	counter = n_spaces + n_zeros + list->str_len;
	if (!(list->flags & MINUS))
		while (n_spaces-- > 0)
			write(1, " ", 1);
	if (list->sign && counter++)
		write(1, &(list->sign), 1);
	if (list->type == 'p' ||
	((list->type == 'X' || list->type == 'x') && list->flags & HASH))
	{
		if (list->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		counter += 2;
	}
	if (list->type == 'X' && list->flags & HASH)
	{
		write(1, "0X", 2);
		counter += 2;
	}
	while (n_zeros-- > 0)
		write(1, "0", 1);
	write(1, list->string, list->str_len);
	while (n_spaces-- > 0)
		write(1, " ", 1);
	return (counter);
}

int		ft_print_arg(t_args *list)
{
	int		n_zeros;
	int		n_spaces;

	n_spaces = 0;
	n_zeros = 0;
	if (ft_strchr("dif", list->type))
		ft_analise_dif(list, &n_zeros, &n_spaces);
	else if (ft_strchr("oux", list->type))
		ft_analise_oux(list, &n_zeros, &n_spaces);
	else
		ft_analise_cs(list, &n_zeros, &n_spaces);
	return(ft_write_all(list, n_zeros, n_spaces));
}
