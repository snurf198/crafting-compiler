CC = gcc
TARGET = app.out
OBJS = dll.o main.o

test: test.out
	./test.out

dbg_test: test.out
	gdb -q ./test.out

test.out: dll.o dll_test.o
	$(CC) -o test.out dll.o dll_test.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

dll.o:
	$(CC) -c src/dll.c

main.o:
	$(CC) -c src/main.c

dll_test.o:
	$(CC) -c src/tests/dll_test.c

clean:
	rm -rf *.o