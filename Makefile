NAME = libftprintf.a

# dirs
DIR_S = srcs

DIR_O = objs

INCLUDES = ./includes

# files
C_FILES = 	ft_printf.c\
			ft_parse_format.c\
			ft_atoi.c\
			sec_fts.c\
			fields_parsers.c\
			ft_parse_len.c\
			ft_precision_f.c\
			ft_ftoa.c\
			fts_itoa.c\
			ft_utf8_coder.c\
			ft_print_arg.c\
			ft_print_result.c\
			ft_clear_struct.c\
			ft_put_bits.c\

HEADER = $(INCLUDES)/ft_printf.h

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))

OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))\

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra -g

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O):
	mkdir -p objs

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all