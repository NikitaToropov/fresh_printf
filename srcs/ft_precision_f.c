/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:15 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/09 11:18:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_any_body_home(char *str)
{
	while (*str)
	{
		if (*str >= '1' && *str <= '9')
			return (1);
		str++;
	}
	return (0);
}

int		ft_bank_check(t_args *list)
{
	char	*frac;
	int		c;

	frac = ft_strchr(list->string, '.') + 1;
	if (list->precision == 0)
		c = (int)(*(frac - 2) - '0') % 2;
	else
		c = (int)(frac[list->precision - 1] - '0') % 2;
	if (c == 0 && frac[list->precision] == '5' &&
	!ft_any_body_home(&frac[list->precision + 1]))
		return (1);
	return (0);
}

void	ft_lengthen_str(t_args *list, int frac_len)
{
	char	*tmp;
	int		new_len;
	int		old_len;
	int		i;

	old_len = ft_strlen(list->string);
	new_len = old_len - frac_len + list->precision;
	tmp = list->string;
	if (!(list->string = ft_memalloc(new_len + 1)))
		exit(1);
	i = 0;
	while (i < new_len)
	{
		if (i < old_len)
			list->string[i] = tmp[i];
		else
			list->string[i] = '0';
		i++;
	}
	free(tmp);
}

void	ft_add_carry(char *str)
{
	long int		i;
	int				carry;

	i = ft_strlen(str) - 1;
	carry = 1;
	while (i >= 0 && carry && str[i] != '-')
	{
		if (str[i] == '.')
			i--;
		if ((str[i] += 1) > '9')
			str[i] = str[i] - 10;
		else
			carry = 0;
		i--;
	}
	if (carry)
	{
		i = ft_strlen(str);
		while (i >= 0)
		{
			str[i + 1] = str[i];
			i--;
		}
		str[0] = 1;
	}
}

void	ft_precision_f(t_args *list)
{
	int				frac_len;
	char			*frac;

	if (list->precision == -1)
		list->precision = 6;
	if (!(frac = ft_strchr(list->string, '.')))
		return ;
	frac += 1;
	frac_len = ft_strlen(frac);
	if (list->precision < frac_len)
	{
		if (frac[list->precision] > '5' ||
		(frac[list->precision] == '5' && !ft_bank_check(list)))
		{
			frac[list->precision] = '\0';
			ft_add_carry(list->string);
		}
		else
			frac[list->precision] = '\0';
	}
	else
		ft_lengthen_str(list, frac_len);
	if (list->precision == 0 && !(list->flags & HASH) && frac)
		*(frac - 1) = '\0';
}
