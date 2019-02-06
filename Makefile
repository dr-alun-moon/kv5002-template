# Makefile for kv5002

CC=gcc
LDLIBS=-pthread

DEPS=libcounter.c   #list of additional local .c files
OBJS=$(DEPS:.c=.o)

example: main.o $(OBJS)
	$(CC) -o example main.o $(OBJS) $(LDLIBS)

.PHONY: clean

clean:
	rm example $(OBJS)
