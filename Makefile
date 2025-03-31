NAME			= minitalk
NAME_SERVER		= server
NAME_CLIENT		= client

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

HEADER			= minitalk.h

CLIENT_SRCS		= client.c
SERVER_SRCS		= server.c server_utils.c

$(NAME)			: all

$(NAME_CLIENT)	: $(CLIENT_SRCS) $(HEADER)
			$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(NAME_CLIENT)

$(NAME_SERVER)	: $(SERVER_SRCS) $(HEADER)
			$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(NAME_SERVER)

all				: $(NAME_CLIENT) $(NAME_SERVER)

clean			:
			@echo "Nothing to clean. Everything is tidy."
fclean			:
			rm $(NAME_CLIENT) $(NAME_SERVER)

re				: fclean all

.PHONY 			: all clean fclean re
