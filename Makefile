NAME = libminitalk.a
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs

SRCS = server.c client.c ft_aux.c
OBJS = $(SRCS:.c=.o)

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF_LIB) $(NAME) $(SERVER) $(CLIENT)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(SERVER):
	$(CC) $(CFLAGS) server.c  ft_printf/*.c -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c ft_aux.c -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS) $(SERVER) $(CLIENT)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re