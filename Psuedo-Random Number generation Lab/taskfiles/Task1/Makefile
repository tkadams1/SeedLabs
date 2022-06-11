
CC = clang
CFLAGS = -Wall -L/usr/local/opt/openssl@3/lib -L/usr/lib -lssl -lcrypto

all:
		$(CC) $(CFLAGS) Lab2.c -o Lab1
exec:
		./Lab2
clean:
		rm -rf Lab2

test:
		@$(CC) $(CFLAGS) Lab2.c -o Lab2
		@echo "\nRunning Program...\n" 
		@./Lab2
		