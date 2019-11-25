#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // dont forget

//Syntax:
//	%[parameter][flags][width][.precision][length]type

// FLAGS
#define HASH					1
#define ZERO					2
#define MINUS					4
#define SPACE					8
#define PLUS					16
#define APOSTROPHE				32
#define BINARY					64

// LENGTH:
#define SHORT					's'
#define CHAR					'c'
#define LONG					'l'
#define LONG_LONG				'L'
#define LONG_DOUBLE				'D'

// ERRORS
#define MEM_IS_NOT_ALLOC		1
#define UNKNOWN_CHAR			2
#define ARG_OMITTED				3

// FLOATS
#define DBL_DIG					15
#define LDBL_DIG				18

typedef struct					t_float
{
	int							total_bits;
	int							sign;
	short						exponent;
	unsigned long long int		significand;
}								s_float;

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
	// s_float						*float_list;

	char						flags;
	char						length;
	char						type;
	
	char						sign;
	char						*string;
	size_t						str_len;

	struct s_args				*next;
}								t_args;

// secondary functions
char							*ft_strchr(const char *s, int c);
size_t							ft_strlen(const char *s);
void							*ft_memalloc(size_t size);
char							*ft_strdup(const char *s1);
int								ft_is_digit(int c);
int								ft_atoi(const char *str);

char							*ft_itoa(long long n);

char							*ft_itoa_base(unsigned long long n, int base);
char							*ft_itoa_base_upp(unsigned long long n, int base);
void							ft_ftoa(t_args *list);
char							*ft_utf8_coder(unsigned int sym);

// final print
int								ft_print_result(char *str, t_args *list);
int								ft_print_arg(t_args *list);




// format string parsing
t_args							*ft_parse_format(const char *str);
void							ft_parse_len(t_args *list);
void							ft_put_bits(t_args *list);
void							ft_precision_f(t_args *list);

// fields parsers
size_t							ft_find_parameter(char *str, t_args *list);
size_t							ft_find_flag(char c, t_args *list);
size_t							ft_find_width(char *str, t_args *list);
size_t							ft_find_precision(char *str, t_args *list);
size_t							ft_find_length(char *str, t_args *list);


int								ft_printf(const char *format, ...);
void							ft_clear_struct(t_args **first);

#endif