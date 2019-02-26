# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 06:47:20 by akremer           #+#    #+#              #
#    Updated: 2019/02/26 15:43:36 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a

SRC =	ft_atoi_printf.c			\
		ft_flags_printf.c			\
		ft_nbrlen.c					\
		ft_printf.c					\
		ft_putchar_printf.c			\
		ft_set_1.c					\
		ft_set_2.c					\
		ft_set_size.c				\
		ft_putstr_test.c			\
		ft_print_printf.c			\
		ft_print_c.c				\
		ft_print_flags.c			\
		ft_strlen.c					\
		ft_print_s.c				\
		ft_print_nbr.c

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
	@rm -rf $(NAME)

re: fclean all

test: re
	@gcc main_test.c $(NAME)
	@./a.out

propre:	fclean
	@rm -rf a.out

save: propre
	git add *
	git commit -m "Sauvegarde auto"
	git push


