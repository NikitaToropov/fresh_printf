#include "ft_printf.h"

void	ft_fill_w_z_p(s_args *list, char *tmp, int old, int new)
{
	while (new >= 0)
	{
		if (old > 1 || old == new)
			list->arg[new--] = tmp[old--];
		else
			list->arg[new--] = '0';
	}
}

void	ft_fill_w_sp(s_args *list, char *tmp, int old, int new)
{
	if (list->flags & MINUS_FLAG)
	{
		while (new >= 0)
		{
			if (new == old )
				list->arg[new--] = tmp[old--];
			else
				list->arg[new--] = ' ';
		}
	}
	else
	{
		while (new >= 0)
		{
			if (old >= 0)
				list->arg[new--] = tmp[old--];
			else
				list->arg[new--] = ' ';
		}
	}
}

void	ft_fill_w_z(s_args *list, char *tmp, int old, int new)
{
	while (new >= 0)
	{
		if (old >= 0)
			list->arg[new--] = tmp[old--];
		else
			list->arg[new--] = '0';
	}
}

void	ft_width_modifying(s_args *list)
{
	int		old_len;
	int		new_len;
	char	*tmp;

	old_len = ft_strlen(list->arg);
	new_len = list->width;
	if (old_len < new_len)
	{
		tmp = list->arg;
		if (!(list->arg = malloc(sizeof(char) * (list->width + 1))))
			ft_error(1);
		list->arg[list->width] = '\0';
		if (list->type == 'p' && list->flags & ZERO_FLAG)
			ft_fill_w_z_p(list, tmp, old_len, new_len);
		else if (list->flags & ZERO_FLAG && (list->precision != -1 &&
		list->type != 'i' && list->type != 'd' && list->type != 'o' &&
		list->type != 'u' && list->type != 'x' && list->type != 'X'))
			ft_fill_w_z(list, tmp, old_len, new_len);
		else
			ft_fill_w_sp(list, tmp, old_len - 1, new_len - 1);
		free(tmp);
	}
}