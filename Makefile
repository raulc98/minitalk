# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Targets
all: server client

server: server.o
	$(CC) $(CFLAGS) -o server server.o

client: client.o
	$(CC) $(CFLAGS) -o client client.o

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -f *.o server client

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
