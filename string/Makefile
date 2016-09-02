CC      = gcc
CFLAGS  =
EXEC    = target
DEPS    = string.h
OBJS    = string.o target.o

default: clean compile

clean:
	@rm -rf $(EXEC) *.h.gch *.o *.so

compile: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(EXEC)

test: default
	./$(EXEC)

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

lib: clean
	$(CC) -Wall -fPIC -c string.c -o string.o
	$(CC) -shared string.o -o libstring.so

libtest:
	$(CC) -c target.c -o target.o
	$(CC) -Wall -L/opt/lib target.o -o target -lstring
