CC = gcc
TARGET = parser
OBJS = main.o scan.o tree.o expr.o gen.o cg.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c defs.h
	$(CC) -c main.c

scan.o: scan.c defs.h
	$(CC) -c scan.c

tree.o: tree.c defs.h
	$(CC) -c tree.c

expr.o: expr.c defs.h
	$(CC) -c expr.c

gen.o: gen.c defs.h
	$(CC) -c gen.c

cg.o: cg.c defs.h
	$(CC) -c cg.c

.PHONY: test
test: $(TARGET)
	./$(TARGET) in.txt > out.s
	$(CC) -no-pie -o math_bin out.s runtime.c
	./math_bin

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
