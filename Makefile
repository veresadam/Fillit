# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psular <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/17 19:40:57 by psular            #+#    #+#              #
#    Updated: 2017/12/19 15:08:58 by adveres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = ./fillt
INC_DIR = ./fillt
LIB_DIR = ./libft

FUNCTIONS = main map piece read solver
FLAGS = -Wall -Wextra -Werror
LIB_LINK = -L $(LIB_DIR) -lft

SRC = $(patsubst %,$(SRC_DIR)/%.c,$(FUNCTIONS))
OBJ = $(patsubst %,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@$(CC) -I $(LIB_DIR) -I $(INC_DIR) $(FLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIB_LINK) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
