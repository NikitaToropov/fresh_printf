#include "ft_printf.h"

void	ft_add_over_f(s_args *list, int counter)
{
	while (counter >= 0 && list->string[counter] != '-')
	{
		list->string[counter + 1] = list->string[counter];
		counter--;
	}
	list->string[counter + 1] = '1';
}

void	ft_reduce_f(s_args *list, int new)
{
	int		over;
	int		counter;

	over = 0;
	if ((list->precision && list->string[new] >= '5') ||
	(list->precision == 0 && list->string[new + 1] >= '5'))
		over = 1;
	list->string[new] = '\0';
	counter = new - 1;
	while (counter >= 0 && over && list->string[counter] != '-')
	{
		if (list->string[counter] == '.')
			counter--;
		if ((list->string[counter] += 1) > '9')
			list->string[counter--] -= 10;
		else
			over = 0;
	}
	if (over)
		ft_add_over_f(list, new);
	if (list->string[0] == '-' && list->string[1] == '0')
	{
		list->string[0] = '0';
		list->string[1] = '\0';
	}
}

void	ft_lengthen_f(s_args *list, int new)
{
	char	*tmp;
	int		counter;

	tmp = list->string;
	if (!(list->string = (char*)malloc(sizeof(char) * (new + 1))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->string[new] = '\0';
	counter = 0;
	while (tmp[counter])
	{
		list->string[counter] = tmp[counter];
		counter++;
	}
	while (counter < new)
		list->string[counter++] = '0';
	free(tmp);
}

void	ft_precision_f(s_args *list, char *str)
{
	char	*frac;
	int		old;
	int		new;

	if (list->precision == -1)
		list->precision = 6;
	frac = ft_strchr(list->string, '.');
	old = ft_strlen(list->string);
	new = frac - list->string + list->precision;
	if (list->precision != 0)
		new++;
	if (old == new || list->float_arg != list->float_arg ||
	list->float_arg == (list->float_arg + list->float_arg))
		return ;
	else if (old > new)
		ft_reduce_f(list, new);
	else
		ft_lengthen_f(list, new);
}
