# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 06:47:20 by akremer           #+#    #+#              #
#    Updated: 2019/03/19 06:57:44 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_atoi_printf.c			\
		ft_flags_printf.c			\
		ft_nbrlen.c					\
		ft_printf.c					\
		ft_putchar_printf.c			\
		ft_set_1.c					\
		ft_set_2.c					\
		ft_set_size.c				\
		ft_print_printf.c			\
		ft_print_c.c				\
		ft_print_flags.c			\
		ft_strlen.c					\
		ft_print_s.c				\
		ft_print_nbr.c				\
		ft_print_pc.c				\
		ft_plus.c					\
		ft_print_u.c				\
		ft_print_gx.c				\
		ft_print_signed.c			\
		ft_putfloat_printf.c

FLAGS =	-Wall -Wextra -Werror -c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -I includes $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

propre:	fclean
	@rm -rf a.out

save: propre
	git add *
	git commit -m "Sauvegarde auto"
	git push

test: re
	@gcc main.c $(NAME)
	@./a.out
