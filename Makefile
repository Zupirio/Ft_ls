# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arangari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/09 17:18:28 by arangari          #+#    #+#              #
#    Updated: 2017/07/09 18:40:08 by arangari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Werror -Wextra

SRC = *.c

OBJ = *.o

all: $(name)

$(NAME):
	cd libft/ && make
	@gcc - $(CFLAGS) $(SRC) -o $(NAME) -L libft/ -lft

clean:
	@rm -f $(OBJ)

fclean: clean

re: fclean all
