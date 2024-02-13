CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
NAME = push_swap
SRC = srcs/main.c \
srcs/node_control.c \
srcs/parse.c \
srcs/stack_checker.c \
srcs/utils.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT):
	@make -C ./libft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) 

clean:
	@$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re : fclean all
