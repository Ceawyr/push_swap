NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_exit_error.c ft_free.c ft_init_a_bis.c ft_start.c push_swap.c push_to_a.c push_to_b.c push.c \
reverse.c rotate.c sort.c swap.c utiles.c utiles2.c utiles3.c utiles4.c utiles5.c \
fonction/ft_atoi.c fonction/ft_isdigit.c fonction/ft_lstadd_back.c fonction/ft_lstlast.c \
fonction/ft_lstsize.c fonction/ft_split.c fonction/ft_strlcpy.c fonction/ft_strlen.c fonction/ft_lstnew.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
