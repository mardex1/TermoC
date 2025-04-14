CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: wordle run debug clean

wordle:
	$(CC) -g $(SOURCES) $(CFLAGS) -o $@

run:
	./wordle

debug:
	gdb wordle

clean:
	rm wordle