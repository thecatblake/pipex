NAME=pipex
CC=cc
LIBFT=libft/libft.a
CFLAGS= -Wall -Wextra -Werror -g
SRCS=main.c env.c cmd.c
OBJS=$(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all