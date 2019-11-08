#include "ft_printf.h"

void	ft_parse_flags_pl_sp(s_args *list)
{
	int		counter;
	char	*tmp;

	if ((list->flags & SPACE || list->flags & PLUS) && list->string[0] != '-' &&
	(list->type == 'd' || list->type == 'f' || list->type == 'i'))
	{
		tmp = list->string;
		counter = ft_strlen(list->string) + 1;
		if (!(list->string = (char*)malloc(sizeof(char) * (counter + 1))))
			ft_errors(MEM_IS_NOT_ALLOC);
		list->string[counter--] = '\0';
		while (counter > 0)
		{
			list->string[counter] = tmp[counter - 1];
			counter--;
		}
		if (list->flags & PLUS)
			list->string[0] = '+';
		else
			list->string[0] = ' ';
		free(tmp);
	}
}

void	ft_hash_f(s_args *list)
{
	char	*tmp;
	int		counter;

	tmp = list->string;
	counter = ft_strlen(list->string) + 1;
	if (!(list->string = (char*)malloc(sizeof(char) * (counter + 1))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->string[counter--] = '\0';
	list->string[counter--] = '.';
	while (counter >= 0)
	{
		list->string[counter] = tmp[counter];
		counter--;
	}
	free(tmp);
}

void	ft_hash_ox(s_args *list)
{
	char	*tmp;
	int		new;
	int		old;

	tmp = list->string;
	old = ft_strlen(list->string);
	new = old + 1;
	if (list->type == 'x' || list->type == 'X')
		new++;
	if (!(list->string = (char*)malloc(sizeof(char) * (new + 1))))
		ft_errors(MEM_IS_NOT_ALLOC);
	list->string[new] = '\0';
	while (new >= 0)
	{
		if ((list->type == 'o' && new) ||
		((list->type == 'x' || list->type == 'X') && new > 1))
			list->string[new--] = tmp[old--];
		else if (list->type == 'x' && new == 1)
			list->string[new--] = 'x';
		else if (list->type == 'X' && new == 1)
			list->string[new--] = 'X';
		else
			list->string[new--] = '0';
	}
	free(tmp);
}

void	ft_parse_flags_hash(s_args *list)
{
	if (list->flags & HASH)
	{
		if (list->type == 'f' && !ft_strchr(list->string, '.'))
			ft_hash_f(list);
		if (list->type == 'o' || list->type == 'x' || list->type == 'X')
			ft_hash_ox(list);
	}
}
