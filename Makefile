# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arangari <arangari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/12 09:09:20 by arangari          #+#    #+#              #
#    Updated: 2017/09/19 11:59:21 by arangari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_ls.c list.c ft_do_file_check.c

FLAGS = gcc -Wall -Wextra -Werror -o

all : $(NAME)

$(NAME):
		@echo "Compiling $(NAME)..."
		@make -C libft/
		@$(FLAGS) $(NAME) $(SRC) -L libft/ -lft -I libft/includes -I includes

fclean:
	@echo "Cleaning..."
	@make fclean -C libft/
	@rm -f $(NAME)

re : fclean all

norm:
	@norminette $(SRC) includes/ft_ls.h
