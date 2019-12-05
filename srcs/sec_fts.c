/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:32 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/05 18:28:32 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		((unsigned char *)ptr)[size] = (unsigned char)0;
	}
	return (ptr);
}

char		*ft_strdup(const char *s1)
{
	char			*res;
	long long int	ln;

	if (!s1)
		return (NULL);
	ln = 0;
	while (s1[ln])
		ln++;
	if (!(res = ft_memalloc(ln + 1)))
		return (NULL);
	ln--;
	while (ln >= 0)
	{
		res[ln] = s1[ln];
		ln--;
	}
	return (res);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
