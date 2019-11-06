#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <locale.h> // dont rmmbr
# include <stdio.h> // dont rmmbr

//Syntax:
//	%[parameter][flags][width][.precision][length]type

// FLAGS
#define HASH							1
#define ZERO							2
#define MINUS							4
#define SPACE							8
#define PLUS							16
#define APOSTROPHE						32
#define BINARY							64

// LENGTH:
#define SHORT							's'
#define CHAR							'c'
#define LONG							'l'
#define LONG_LONG						'L'
#define LONG_DOUBLE						'D'

// ERRORS
#define MEM_IS_NOT_ALLOC				1
#define UNKNOWN_CHAR					2
#define ARG_OMITTED						3


typedef struct							t_float
{
	int									total_bits;
	int									sign;
	short								exponent;
	unsigned long long int				significand;
}										s_float;

typedef struct							t_args
{
	int									order_counter;
	
	int									n_arg_width;
	int									n_arg_precision;
	int									n_arg;

	int									width;
	int									precision;
	
	unsigned long long int				int_arg;
	long double							float_arg;
	s_float								*float_list;

	char								flags;
	char								length;
	char								type;
	
	char								*arg_str;
	struct t_args						*next;
}										s_args;

// secondary functions
void		ft_errors(int code);
int			ft_arg_is_integer(char type);

char		*ft_strdup(const char *s1);
int			ft_atoi(const char *str);
char		*ft_itoa(long long n);
char		*ft_itoa_base(unsigned long long n, int base);
char		*ft_itoa_base_uppercase(unsigned long long n, int base);
char		*ft_itoa_pointer(unsigned long long n);


// convert args from int/float to string
void		ft_convert_to_string(s_args *first_list);

// format string parsing
int			ft_find_length(char *str, s_args *list);
int			ft_find_precision(char *str, s_args *list);
int			ft_find_width(char *str, s_args *list);
int			ft_find_flag(char str, s_args *list);
int			ft_find_parameter(char *str, s_args *list);
s_args		*ft_format_string_parse(char *str);

int			ft_printf(const char *format, ...);

#endif