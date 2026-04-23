CC = gcc

TARGET = c-calc

SRC = src/main.c

CFLAGS = -Wall -Iinclude

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)