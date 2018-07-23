# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vradchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 15:51:29 by vradchen          #+#    #+#              #
#    Updated: 2018/03/25 15:51:30 by vradchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

FLAGS =		-Wall -Wextra -Werror
H =			./printf.h

OPT =		-c -I $(H)

SOURCES =	./ft_printf.c \
			\
			./start/ft_crossroad.c ./start/ft_bublik.c ./start/ft_ointer.c \
			./start/ft_n.c ./start/ft_valid.c ./start/ft_invalid.c\
			\
			./uni/ft_uni.c ./uni/ft_usize.c\
			\
			./octa/ft_octa.c ./octa/ft_octa_left.c ./octa/ft_octa_right.c\
			\
			./hex/ft_hex.c ./hex/ft_hex_left.c \
			./hex/ft_hex_right.c\
			\
			./lib/ft_itoa_base.c ./lib/ft_uitoa_base.c ./lib/ft_double_c.c\
			./lib/ft_initial_style.c ./lib/ft_itoa2.c\
			\
			./int/ft_number.c ./int/ft_number_left.c \
			./int/ft_number_right.c \
			\
			./char/ft_char.c ./char/ft_uchar.c\
			\
			./string/ft_string.c ./string/ft_ustring_left.c \
			./string/ft_ustring_right.c

OBJ =		./ft_printf.o ./ft_crossroad.o ./ft_bublik.o ./ft_ointer.o\
			./ft_n.o ./ft_uitoa_base.o ./ft_uni.o ./ft_usize.o\
			./ft_valid.o ./ft_invalid.o\
			\
			./ft_octa_left.o ./ft_octa_right.o ./ft_octa.o\
			\
			./ft_hex.o ./ft_hex_right.o ./ft_hex_left.o\
			\
			./ft_itoa_base.o ./ft_uitoa_base.o ./ft_double_c.o\
			./ft_initial_style.o ./ft_itoa2.o\
			\
			./ft_number.o ./ft_number_left.o ./ft_number_right.o \
			\
			./ft_char.o ./ft_uchar.o \
			\
			./ft_string.o ft_ustring_left.o ft_ustring_right.o

all: $(NAME)

$(NAME):
			@ gcc $(FLAGS) $(OPT) $(SOURCES)
			@ ar rc $(NAME) $(OBJ)
			@ ranlib $(NAME)

clean:
			@ /bin/rm -f $(OBJ)

fclean: clean
			@ /bin/rm -f $(NAME)

re: fclean all
