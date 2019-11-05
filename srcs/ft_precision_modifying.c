#include "ft_printf.h"

void	ft_precision_dioux(s_args *list)
{
	int		old_len;
	int		new_len;
	char	*tmp;

	old_len = ft_strlen(list->arg);
	new_len = list->precision;
	if (new_len > old_len)
	{
		tmp = list->arg;
		if (!(list->arg = malloc(sizeof(char) *( list->precision + 1))))
			ft_error(1);
		while (new_len >= 0)
		{
			if (old_len >= 0)
				list->arg[new_len--] = tmp[old_len--];
			else
				list->arg[new_len--] = '0';
		}
		free(tmp);
	}
}

void	ft_precision_p(s_args *list)
{
	int		old_len;
	int		new_len;
	char	*str;

	old_len = ft_strlen(list->arg);
	new_len = list->precision + 2;
	if (old_len < new_len)
	{
		if (!(str = (char*)malloc(sizeof(char) * (new_len + 1))))
			ft_error(1);
		while (new_len >= 0)
		{
			if (old_len > 1 || old_len == new_len)
				str[new_len--] = (list->arg)[old_len--];
			else
				str[new_len--] = '0';
		}
		free(list->arg);
		list->arg = str;
	}
}

void	ft_reduce_f(s_args *list, int new_len)
{
	int		over;
	int		counter;

	over = 0;
	if ((list->precision && list->arg[new_len] >= '5') ||
	(list->precision == 0 && list->arg[new_len + 1] >= '5'))
		over = 1;
	list->arg[new_len] = '\0';
	counter = new_len - 1;
	while (counter >= 0 && over && list->arg[counter] != '-')
	{
		if (list->arg[counter] == '.')
			counter--;
		if ((list->arg[counter] += 1) > '9')
			list->arg[counter--] -= 10;
		else
			over = 0;
	}
	if (over)
	{
		counter = new_len;
		while (counter >= 0 && list->arg[counter] != '-')
		{
			list->arg[counter + 1] = list->arg[counter];
			counter--;
		}
		list->arg[counter + 1] = '1';
	}
	if (list->arg[0] == '-' && list->arg[1] == '0')
	{
		list->arg[0] = '0';
		list->arg[1] = '\0';
	}
}

void	ft_lengthen_f(s_args *list, int new_len)
{
	char	*tmp;
	int		counter;

	tmp = list->arg;
	if (!(list->arg = (char*)malloc(sizeof(char) * (new_len + 1))))
		ft_error(1);
	list->arg[new_len] = '\0';
	counter = 0;
	while (tmp[counter])
	{
		list->arg[counter] = tmp[counter];
		counter++;
	}
	while (counter < new_len)
	{
		list->arg[counter] = '0';
		counter++;
	}
	free(tmp);
}

void		ft_precision_f(s_args *list)
{
	char	*frac;
	int		old_len;
	int		new_len;

	if (list->precision == -1)
		list->precision = 6;
	frac = ft_strchr(list->arg, '.');
	old_len = ft_strlen(list->arg);
	new_len = frac - list->arg + list->precision;
	if (list->precision)
		new_len++;
	if (old_len == new_len || list->arg[0] == 'n' ||
	list->arg[0] == 'i' || list->arg[1] == 'i')
		return ;
	else if (old_len > new_len)
		ft_reduce_f(list, new_len);
	else
		ft_lengthen_f(list, new_len);
}

void	ft_precision_modifying(s_args *list)
{
	int		old_len;

	if (list->type == 'f' && !(list->flags & BIN_FLAG))
			ft_precision_f(list);
	else if (list->type == 'p' && list->precision != -1 &&
	!(list->flags & BIN_FLAG))
			ft_precision_p(list);
	else if (list->precision != -1 && list->type == 's')
	{
		old_len = ft_strlen(list->arg);
		if (old_len > list->precision)
			list->arg[list->precision] = '\0';
	}
	else if(list->precision != -1 &&
	(list->type == 'd' || list->type == 'i' || list->type == 'o' ||
	list->type == 'x' || list->type == 'X' || list->type == 'u'))
		ft_precision_dioux(list);
}