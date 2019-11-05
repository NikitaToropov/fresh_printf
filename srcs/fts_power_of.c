#include "ft_printf.h"

unsigned long long int		ft_power_of_five(short i)
{
	unsigned long long int		res;

	res = 5;
	while (i > 1)
	{
		res *= 5;
		i--;
	}

	return (res);
}

unsigned long long int		ft_power_of_two(short i)
{unsigned long long int		res;

	res = 2;
	while (i > 1)
	{
		res *= 2;
		i--;
	}

	return (res);}