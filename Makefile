CC = gcc

TARGET = c-calc

SRC = src/main.c src/calc.c src/input.c src/logic.c
# sources shared with the test suite (everything except main)
LIB_SRC = src/calc.c src/input.c src/logic.c

CFLAGS = -Wall -Iinclude

RELEASE = -O3 -s

TEST_TARGET = tests/test_calc

.PHONY: all clean release test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# build the shared library objects as relocatable objects so the test
# suite can reuse them without dragging in main()
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# the test binary links the library objects plus the test runner, but not main.c
$(TEST_TARGET): $(LIB_SRC:.c=.o) tests/test_calc.c
	$(CC) $(CFLAGS) tests/test_calc.c $(LIB_SRC:.c=.o) -o $(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) src/*.o

release:
	$(CC) $(CFLAGS) $(RELEASE) $(SRC) -o $(TARGET)
