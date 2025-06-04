NAME = minishell

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS = main.c parsing/parsing.c parsing/split.c \
	parsing/lst/lst_cmd.c parsing/lst/lst_heredoc.c \
	parsing/lst/lst_lexer.c parsing/lst/lst_redir.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re