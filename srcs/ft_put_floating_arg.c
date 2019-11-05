#include "ft_printf.h"

void	ft_length_counter(int *i_len, int *f_len, int s_dig, long double ld)
{
	long double		ld_copy;

	ld_copy = ld;
	*i_len = 1;
	while ((ld_copy /= 10) >= 1)
		*i_len += 1;
	*f_len = 0;
	if (*i_len == 1 && ld < 1)
	{
		while ((ld *= 10) < 1)
			*f_len += 1;
		*f_len += s_dig;
	}
	else if (*i_len < s_dig)
		*f_len = s_dig - *i_len;
	if (*f_len < 6)
		*f_len = 6;
}

void	ft_fill_by_int(char *str, int counter, int *dyn_s_dig, long double ld)
{
	str[counter] = '.';
	counter--;
	while (counter >= 0)
	{
		if (counter >= *dyn_s_dig || ld < 1)
			str[counter] = '0';
		else
		{
			str[counter] = ((unsigned long long int)ld % 10) + '0';
			*dyn_s_dig -= 1;
		}
		ld /= 10;
		counter--;
	}
}

void	ft_fill_by_fr(char *s, int f_len, int dyn_d, int stat_d, long double ld)
{
	int		counter;

	counter = 0;
	while (counter < f_len)
	{
		ld *= 10;
		if (!dyn_d || (dyn_d == stat_d && (f_len - counter) > stat_d))
			s[counter] = '0';
		else
		{
			s[counter] = ((unsigned long long int)ld % 10) + '0';
			dyn_d--;
		}
		counter++;
	}
}

char	*ft_ld_string(int s_dig, int i_len, int f_len, long double ld)
{
	char				*str;
	int					len;
	int					dyn_s_dig;

	dyn_s_dig = s_dig;
	len = f_len + i_len + 1;
	if (ld < 0)
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		ft_error(1);
	str[len] = '\0';
	if (ld < 0)
	{
		str[0] = '-';
		ft_fill_by_int(&str[1], i_len, &dyn_s_dig, ld * (-1));
		ft_fill_by_fr(&str[i_len + 2], f_len, dyn_s_dig, s_dig, ld * (-1));
	}
	else
	{
		ft_fill_by_int(str, i_len, &dyn_s_dig, ld);
		ft_fill_by_fr(&str[i_len + 1], f_len, dyn_s_dig, s_dig, ld);
	}
	return (str);
}

void	ft_put_floating_arg(s_args *list, long double argument)
{
	int				int_len;
	int				frac_len;
	long double 	tmp;
	int				sign_dig; //significant digits

	if (!argument)
		list->arg = ft_strdup("0.000000");
	else if (argument != argument)
		list->arg = ft_strdup("nan");
	else if (argument == (argument + argument) && argument > 0)
		list->arg = ft_strdup("inf");
	else if (argument == (argument + argument) && argument < 0)
		list->arg = ft_strdup("-inf");
	else
	{
		tmp = argument;
		if (tmp < 0)
			tmp *= -1;
		if (list->length == 'F')
			sign_dig = LDBL_DIG;
		else
			sign_dig = DBL_DIG;
		ft_length_counter(&int_len, &frac_len, sign_dig, tmp);
		list->arg = ft_ld_string(sign_dig, int_len, frac_len, argument);
	}
}