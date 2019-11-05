#include "ft_printf.h"

void	ft_modify_str_arg(s_args *first_list)
{
	s_args		*list;

	list = first_list;
	while (list)
	{
		if (!(list->arg))
		{

			list->arg = (char*)malloc(sizeof(char) * 2);
			(list->arg)[0] = list->type;
			(list->arg)[1] = '\0';
		}
		ft_precision_modifying(list);
		if (list->width != -1)
			ft_width_modifying(list);
		if (list->flags)
			ft_flags_modifying(list);
		list = list->next;
	}
}