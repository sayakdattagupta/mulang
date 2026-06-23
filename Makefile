CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = bin/parser
SRCDIR = src
OBJDIR = build

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CC) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: test
test: $(TARGET)
	./$(TARGET) tests/in.txt > tests/out.s
	$(CC) -no-pie -o bin/math_bin tests/out.s runtime/runtime.c
	./bin/math_bin

.PHONY: clean
clean:
	rm -rf build bin tests/out.s
