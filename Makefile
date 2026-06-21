CC = gcc
TARGET = parser
OBJS = main.o scan.o tree.o expr.o interp.o

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

interp.o: interp.c defs.h
	$(CC) -c interp.c

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
