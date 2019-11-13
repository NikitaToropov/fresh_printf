#include "ft_printf.h"

unsigned int	ft_uns_len(unsigned long long nb, int base)
{
	unsigned int	ln;

	ln = 1;
	while (nb /= base)
		ln++;
	return (ln);
}

char			*ft_itoa(long long n)
{
	char					*result;
	unsigned long long		number;
	unsigned int			len;

	if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	number = (unsigned long long)(n);
	if (n < 0 && (len += 1))
		number = (unsigned long long)(n * -1);
	len += ft_uns_len(number, 10);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		exit(1);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	while (number)
	{
		result[--len] = number % 10 + '0';
		number /= 10;
	}
	return (result);
}

char			*ft_itoa_base(unsigned long long n, int base)
{
	char					*result;
	unsigned int			len;
	unsigned int			modulo;
	char					*l;

	l = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_uns_len(n, base);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		exit(1);
	result[len] = '\0';
	while (n > 0)
	{
		modulo = n % base;
		result[--len] = modulo + '0';
		n /= (long long)base;
	}
	return (result);
}

char			*ft_itoa_base_upp(unsigned long long n, int base)
{
	char					*result;
	char					*l;
	unsigned int			len;
	unsigned int			modulo;

	l = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_uns_len(n, base);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		exit(1);
	result[len] = '\0';
	while (n > 0)
	{
		modulo = n % base;
		result[--len] = modulo + '0';
		n /= (long long)base;
	}
	return (result);
}

char			*ft_itoa_pointer(unsigned long long n)
{
	char					*result;
	char					*l;
	unsigned int			len;
	unsigned int			modulo;

	l = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0x0"));
	len = ft_uns_len(n, 16) + 2;
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		exit(1);
	result[len] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (n > 0)
	{
		modulo = n % 16;
		result[--len] = modulo + '0';
		n /= (long long)16;
	}
	return (result);
}
