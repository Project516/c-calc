CC = gcc

TARGET = c-calc

SRC = src/main.c

CFLAGS = -Wall -Iinclude

RELEASE = -O3 -s

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

release:
	$(CC) $(CFLAGS) $(RELEASE) $(SRC) -o $(TARGET)