CC=gcc
CFLAGS=-I.
DEPS = sqlite3.h
OBJ = main.o sqlite3secure.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
