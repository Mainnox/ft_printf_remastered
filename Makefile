NAME = libftprint.a

SRC =	ft_atoi_printf.c			\
		ft_flags_printf.c			\
		ft_nbrlen.c					\
		ft_printf.c					\
		ft_putchar_printf.c			\
		ft_set_1.c					\
		ft_set_2.c					\
		ft_set_size.c				\
		# Surprime les test
		ft_putstr_test.c			\
		main_test.c					

FLAGS =	-Wall -Wextra -Werror -c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc -I includes $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all