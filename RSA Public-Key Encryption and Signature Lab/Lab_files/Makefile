
CC = clang
CFLAGS = -Wall -L/usr/local/opt/openssl@3/lib -L/usr/lib -lssl -lcrypto

all:
		$(CC) $(CFLAGS) Lab3.c -o Lab3
exec:
		./Lab3
clean:
		rm -rf Lab3

test:
		@$(CC) $(CFLAGS) Lab3.c -o Lab3
		@echo "\nRunning Program...\n" 
		@./Lab3
		