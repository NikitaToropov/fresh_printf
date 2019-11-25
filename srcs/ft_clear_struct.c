#include "ft_printf.h"

void	ft_clear_struct(t_args **first)
{
	t_args		*tmp;
	t_args		*tmp_1;

	tmp = *first;
	while (tmp)
	{
		tmp_1 = tmp->next;
		if (tmp->string)
			free(tmp->string);
		free(tmp);
		tmp = tmp_1;
	}
	first = NULL;
}
