#include "ft_printf.h"

// void	ft_hash_modifying(s_args *list)
// {

// }


void	ft_flags_modifying(s_args *list)
{
	if (list->flags & HASH_FLAG)
		ft_hash_modifying(list);
}
