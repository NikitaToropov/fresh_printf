/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:21:28 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/09 11:53:47 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HASH					1
# define ZERO					2
# define MINUS					4
# define SPACE					8
# define PLUS					16
# define APOSTROPHE				32
# define BINARY					64
# define SHORT					's'
# define CHAR					'c'
# define LONG					'l'
# define LONG_LONG				'L'
# define LONG_DOUBLE			'D'
# define DBL_DIG				20
# define LDBL_DIG				20

typedef struct					s_args
{
	size_t						order_counter;
	size_t						num_width;
	size_t						num_precision;
	size_t						num_arg;
	int							width;
	int							precision;
	unsigned long long int		int_arg;
	long double					float_arg;
	char						flags;
	char						length;
	char						type;
	char						sign;
	char						*string;
	size_t						str_len;
	struct s_args				*next;
}								t_args;

char							*ft_strchr(const char *s, int c);
size_t							ft_strlen(const char *s);
void							*ft_memalloc(size_t size);
char							*ft_strdup(const char *s1);
int								ft_is_digit(int c);
int								ft_atoi(const char *str);
char							*ft_itoa(long long n);
char							*ft_itoa_base(unsigned long long n, int base);
char							*ft_itoa_base_upp(unsigned long long n,
								int base);
void							ft_ftoa(t_args *list);
char							*ft_utf8_coder(unsigned int sym);
int								ft_print_result(char *str, t_args *list);
int								ft_print_arg(t_args *list);
t_args							*ft_parse_format(const char *str);
void							ft_parse_len(t_args *list);
void							ft_put_bits(t_args *list);
void							ft_precision_f(t_args *list);
size_t							ft_find_parameter(char *str, t_args *list);
size_t							ft_find_flag(char c, t_args *list);
size_t							ft_find_width(char *str, t_args *list);
size_t							ft_find_precision(char *str, t_args *list);
size_t							ft_find_length(char *str, t_args *list);
int								ft_printf(const char *format, ...);
void							ft_clear_struct(t_args **first);

#endif
