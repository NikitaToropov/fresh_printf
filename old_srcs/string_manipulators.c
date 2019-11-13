#include "ft_printf.h"

void	ft_copy(char *old_str, char *new_str)
{
	long long int		i;

	i = 0;
	while (old_str[i])
	{
		new_str[i] = old_str[i];
		i++;
	}
}

void	ft_fill_by_while(char *str, char n, unsigned int limiter)
{
	long int		i;

	i = 0;
	while (i < limiter)
		str[i++] = n;
}

void	ft_shift_right_by(char *str, unsigned int limiter)
{
	long int		back_c;

	back_c = ft_strlen(str);
	while(back_c >= 0)
	{
		str[back_c + limiter] = str[back_c];
		back_c--;
	}
}