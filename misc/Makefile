CC      = gcc
CFLAGS  =
EXEC    = target
DEPS    = misc.h
OBJS    = misc.o target.o

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
	$(CC) -Wall -fPIC -c misc.c -o misc.o
	$(CC) -shared misc.o -o libmisc.so

libtest:
	$(CC) -c target.c -o target.o
	$(CC) -Wall -L/opt/lib target.o -o target -lmisc
