CC			= gcc
CFLAGS		= -std=c99 -pedantic -g
EXECUTABLE	= sudokubot
OBJECTS		= main.o board.o list.o mem_wrap.o

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

main.o: main.c board.h boolean.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h boolean.h list.h mem_wrap.h
	$(CC) $(CFLAGS) -c board.c

list.o: list.c list.h boolean.h mem_wrap.h
	$(CC) $(CFLAGS) -c list.c

mem_wrap.o: mem_wrap.c mem_wrap.h
	$(CC) $(CFLAGS) -c mem_wrap.c

clean:
	rm $(EXECUTABLE) $(OBJECTS)
