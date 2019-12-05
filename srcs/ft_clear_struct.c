/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:37 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:27:38 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
