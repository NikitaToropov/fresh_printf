/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:47 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:27:47 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lengths(size_t *i_len, size_t *f_len, size_t s_dig, long double ld)
{
	long double		ld_cpy;

	ld_cpy = ld;
	*i_len = 1;
	while ((ld_cpy /= 10) >= 1)
		*i_len += 1;
	*f_len = s_dig;
	if (*i_len == 1 && ld < 1)
		while ((ld *= 10) < 1)
			*f_len += 1;
	else if (*i_len < s_dig)
		*f_len -= *i_len;
	else
		*f_len = 0;
}

void	ft_fill_int(char *str, int i_len, size_t sign_dig, long double ld)
{
	long int	i;

	str[i_len] = '.';
	i = i_len - 1;
	while (i >= 0)
	{
		if ((size_t)i >= sign_dig || ld < 1)
			str[i--] = '0';
		else
			str[i--] = ((unsigned long long int)ld % 10) + '0';
		ld /= 10;
	}
}

void	ft_fill_frac(char *str, size_t frac_len, long double ld)
{
	size_t		i;

	i = 0;
	while (i < frac_len)
	{
		ld *= 10;
		str[i++] = ((unsigned long long int)ld % 10) + '0';
	}
}

char	*ft_convert_ld(size_t sign_dig, long double ld)
{
	size_t			int_len;
	size_t			frac_len;
	size_t			len;
	char			*res;

	ft_lengths(&int_len, &frac_len, sign_dig, ld);
	len = int_len + frac_len + 1;
	if (!(res = ft_memalloc(len + 1)))
		exit(1);
	ft_fill_int(res, int_len, sign_dig, ld);
	if (frac_len)
		ft_fill_frac(&res[int_len + 1], frac_len, ld);
	return (res);
}

void	ft_ftoa(t_args *list)
{
	size_t				sign_dig;

	if (!list->float_arg)
		list->string = ft_strdup("0.");
	else if (list->float_arg != list->float_arg)
		list->string = ft_strdup("nan");
	else if (list->float_arg == (list->float_arg + list->float_arg)
	&& list->float_arg > 0)
		list->string = ft_strdup("inf");
	else if (list->float_arg == (list->float_arg + list->float_arg)
	&& list->float_arg < 0)
		list->string = ft_strdup("-inf");
	else
	{
		if (list->float_arg < 0)
		{
			list->sign = '-';
			list->float_arg *= -1;
		}
		sign_dig = DBL_DIG;
		if (list->length == LONG_DOUBLE)
			sign_dig = LDBL_DIG;
		list->string = ft_convert_ld(sign_dig, list->float_arg);
	}
}
