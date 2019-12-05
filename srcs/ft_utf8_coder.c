/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_coder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:20 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:28:21 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utf8_coder(unsigned int sym)
{
	char		*str;

	if (!(str = ft_memalloc(5)))
		exit(1);
	if (sym < 128)
		str[0] = (char)sym;
	else if (sym < 2048)
	{
		str[0] = (unsigned char)(((sym >> 6) & 31) | 192);
		str[1] = (unsigned char)((sym & 63) | 128);
	}
	else if (sym < 65536)
	{
		str[0] = (unsigned char)(((sym >> 12) & 15) | 224);
		str[1] = (unsigned char)(((sym >> 6) & 63) | 128);
		str[2] = (unsigned char)((sym & 63) | 128);
	}
	else
	{
		str[0] = (unsigned char)(((sym >> 18) & 7) | 240);
		str[1] = (unsigned char)(((sym >> 12) & 63) | 128);
		str[2] = (unsigned char)(((sym >> 6) & 63) | 128);
		str[3] = (unsigned char)((sym & 63) | 128);
	}
	return (str);
}
