NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs

SRCS = ft_preptchr.c ft_prepthx.c ft_preptnbr.c ft_preptnbru.c ft_preptstr.c ft_preptvdhx.c ft_printf.c ft_putchr.c ft_puthx.c ft_putnbr.c ft_putnbru.c ft_putstr.c ft_swparam.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re