#include "ft_printf.h"

char	*ft_utf_8_coder(int sym)
{
	char		*str;
	
	if (sym >= 0 && sym <= 127) //00000000-0000007F
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			ft_error(1);
		str[0] = (char)sym;
		str[1] = '\0';
	}
	else if (sym > 127 && sym <= 2047) //00000080-000007FF
	{
		if (!(str = (char*)malloc(sizeof(char) * 3)))
			ft_error(1);
		str[0] = (unsigned char)(((sym >> 6) & 31) | 192);
		str[1] = (unsigned char)((sym & 63) | 128);
		str[2] = '\0';
	}
	else if (sym > 2047 && sym <= 65535) //00000800-0000FFFF
	{
		if (!(str = (char*)malloc(sizeof(char) * 4)))
			ft_error(1);
		str[0] = (unsigned char)(((sym >> 12) & 15) | 224);
		str[1] = (unsigned char)(((sym >> 6) & 63) | 128);		
		str[2] = (unsigned char)((sym & 63) | 128);
		str[3] = '\0';
	}
	else //00010000-0010FFFF
	{
		if (!(str = (char*)malloc(sizeof(char) * 5)))
			ft_error(1);
		str[0] = (unsigned char)(((sym >> 18) & 7) | 240);
		str[1] = (unsigned char)(((sym >> 12) & 63) | 128);
		str[2] = (unsigned char)(((sym >> 6) & 63) | 128);
		str[3] = (unsigned char)((sym & 63) | 128);
		str[4] ='\0';
	}
	return (str);
}