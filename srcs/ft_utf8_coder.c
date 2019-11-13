#include "ft_printf.h"

char	*ft_utf8_coder(int sym)
{
	char		str[5];

	str[0] = (char)sym;
	str[1] = '\0';
	if (sym > 127 && sym <= 2047 && !(str[2] = '\0'))
	{
		str[0] = (unsigned char)(((sym >> 6) & 31) | 192);
		str[1] = (unsigned char)((sym & 63) | 128);
	}
	else if (sym > 2047 && sym <= 65535 && !(str[3] = '\0'))
	{
		str[0] = (unsigned char)(((sym >> 12) & 15) | 224);
		str[1] = (unsigned char)(((sym >> 6) & 63) | 128);
		str[2] = (unsigned char)((sym & 63) | 128);
	}
	else if (sym > 65535 && !(str[4] = '\0'))
	{
		str[0] = (unsigned char)(((sym >> 18) & 7) | 240);
		str[1] = (unsigned char)(((sym >> 12) & 63) | 128);
		str[2] = (unsigned char)(((sym >> 6) & 63) | 128);
		str[3] = (unsigned char)((sym & 63) | 128);
	}
	return (ft_strdup(str));
}
