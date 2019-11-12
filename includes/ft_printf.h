#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // dont forget

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

// FLOATS
#define DBL_DIG							15
#define LDBL_DIG						18

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
	
	char								*string;
	struct t_args						*next;
}										s_args;

// secondary functions
void		ft_errors(int code);

char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlen(const char *s);

int				ft_atoi(const char *str);
char			*ft_itoa(long long n);
char			*ft_itoa_base(unsigned long long n, int base);
char			*ft_itoa_base_upp(unsigned long long n, int base);
char			*ft_itoa_pointer(unsigned long long n);
void			ft_ftoa(s_args *list);
char			*ft_utf8_coder(int sym);
void			ft_clear_the_struct(s_args **first);


// final print
int			ft_final_print(char *format, s_args *first_list);

// modifying
void			ft_string_modifying(s_args *list);
void			ft_parse_precision(s_args *list, char *str);
void			ft_precision_f(s_args *list, char *str);
void			ft_parse_flag_h(s_args *list, char *str);
// void			ft_parse_flag_p(s_args *list, char *str);


void		ft_copy(char *old_str, char *new_str);
void		ft_shift_right_by(char *str, unsigned int limiter);
void		ft_fill_by_while(char *str, char n, unsigned int limiter);




// convert args from int/float to chars
void		ft_convert_to_string(s_args *list);
void		ft_put_bits_in_tne_list(s_args *list);
void		ft_parse_len(s_args *list);

// format string parsing
int			ft_find_length(char *str, s_args *list);
int			ft_find_precision(char *str, s_args *list);
int			ft_find_width(char *str, s_args *list);
int			ft_find_flag(char str, s_args *list);
int			ft_find_parameter(char *str, s_args *list);
s_args		*ft_format_string_parse(char *str);

int			ft_printf(const char *format, ...);

#endif