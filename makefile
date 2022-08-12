TARGET=urna
LIBS=
CC=gcc
CFLAGS= -std=c99 -g -Wall -Werror -Wno-unused-variable

default: $(TARGET)

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	-rm -f *.o *.tmp *.orig $(TARGET)