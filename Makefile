NAME	=	minishell

SRCS	= 	srcs/main.c srcs/builtin_command.c srcs/run_command.c srcs/split.c

INC =	-I./includes


LEAKS	=	-g3 -fsanitize=address

LIBFT	=	libft.a

LIBS	=	-L./libs/libft -lft

#FLAG	= -Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -rf

all		: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libs/libft

$(NAME)	: $(LIBFT)
	$(CC) $(SRCS) $(LIBS) $(INC) -o $(NAME)

clean	:
	$(MAKE) -C ./libs/libft clean
	rm -rf $(OBJS)

fclean	:
	$(MAKE) -C ./libs/libft fclean
	rm -rf $(NAME)

re		: fclean all
