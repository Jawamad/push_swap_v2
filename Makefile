# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florian <florian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:51:14 by florian           #+#    #+#              #
#    Updated: 2024/04/15 15:25:18 by florian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./libft/libft.a
NAME = push_swap
NAME_BONUS = checker

# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #

MAIN = main.c
SRC = node_control.c \
parse.c \
stack_checker.c \
utils.c \
move_write.c \
move.c \
reset.c \
rotate_and_push.c \
sort.c \

SRC_BONUS = checker.c \
get_next_line_utils.c \
get_next_line.c \

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE_DIR	= inc/

SRCS		= $(addprefix $(SRC_DIR), $(SRC))
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ))

SRCS_BONUS	= $(addprefix $(SRC_DIR), $(SRC_BONUS))
OBJ_BONUS 	= $(SRC_BONUS:.c=.o)
OBJS_BONUS	= $(addprefix $(OBJ_DIR), $(OBJ_BONUS))

OBJ_MAIN  	= $(MAIN:.c=.o)
OBJS_MAIN	= $(addprefix $(OBJ_DIR), $(OBJ_MAIN))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all : $(NAME)

bonus : $(NAME_BONUS) 

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS) $(OBJS_MAIN) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_MAIN) $(LIBFT)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@${CC} ${CFLAGS} -c $< -o $@ -I $(INCLUDE_DIR)

$(OBJ_DIR)%.o: $(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_BONUS)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFT)

re : fclean all

.PHONY: all bonus clean fclean re
