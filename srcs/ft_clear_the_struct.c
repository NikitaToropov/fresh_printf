#include "ft_printf.h"

void	ft_clear_the_struct(s_args **first)
{
	s_args		*tmp;
	s_args		*tmp_1;

	tmp = *first;
	while (tmp)
	{
		tmp_1 = tmp->next;
		free(tmp->arg);
		free(tmp);
		tmp = tmp_1;
	}
	first = NULL;
}