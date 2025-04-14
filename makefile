CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: wordle run clean

wordle:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./wordle

debug:
	gdb wordle

clean:
	rm wordle