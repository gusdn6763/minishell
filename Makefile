NAME =	minishell

SRCS =	srcs/main.c\
		srcs/parser.c\
		srcs/pipe.c\
		srcs/command.c\
		srcs/args.c\
		srcs/bin.c\
		srcs/builtins.c\
		srcs/bash.c\
		srcs/cd.c\
		srcs/export.c\
		srcs/unset.c\
		srcs/utils.c\
		srcs/lens.c\
		srcs/remove.c\
		srcs/exit.c\

OBJS = $(SRCS:.c=.o)

INC =	-I./includes

CC = gcc

CFLAGS += -Wall -Werror -Wextra 


RM = rm -rf

LIBFT	=	libft.a

LIBS	=	-L./libft -lft


all:		$(NAME)


$(LIBFT):
	$(MAKE) -C ./libft

$(NAME)	: $(LIBFT)
	$(CC) $(SRCS) $(LIBS) $(INC) -o $(NAME)

clean	:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean	:
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)
re:		fclean all

.PHONY:		all clean fclean re leaks git norme
