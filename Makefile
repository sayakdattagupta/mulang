CC = gcc
TARGET = parser
OBJS = main.o scan.o tree.o expr.o gen.o cg.o stmt.o keyword.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c defs.h data.h
	$(CC) -c main.c

scan.o: scan.c defs.h data.h
	$(CC) -c scan.c

tree.o: tree.c defs.h
	$(CC) -c tree.c

expr.o: expr.c defs.h data.h
	$(CC) -c expr.c

gen.o: gen.c defs.h
	$(CC) -c gen.c

cg.o: cg.c defs.h
	$(CC) -c cg.c

stmt.o: stmt.c defs.h data.h
	$(CC) -c stmt.c

keyword.o: keyword.c defs.h
	$(CC) -c keyword.c

.PHONY: test
test: $(TARGET)
	./$(TARGET) in.txt > out.s
	$(CC) -no-pie -o math_bin out.s runtime.c
	./math_bin

.PHONY: clean
clean:
	rm -f *.o out.s math_bin $(TARGET)
