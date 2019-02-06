# Makefile for kv5002

CC=gcc
LDLIBS=-pthread

DEPS=libcounter.c   #list of additional local .c files
OBJS=$(DEPS:.c=.o)

example: example.o $(OBJS)


.PHONY: clean

clean:
	rm example $(OBJS)
