.SUFFIXES:
.SUFFIXES: .c .o

CC=gcc
PROGRAM=client
CPPFLAGS=-Wall -Wextra -Wformat -std=c99 `sdl-config --cflags`
LDLIBS=-pthread -lm -ldl -lSDL -lGL -lX11
OBJDIR=obj
OUTDIR=bin

vpath %.c src
vpath %.h src

objects = $(addprefix $(OBJDIR)/, app.o game.o thread.o main.o log.o)
headers = $(log.h app.h game.h thread.h)

ku: $(objects)
	$(CC) $(CPPFLAGS) -g -o $(OUTDIR)/$(PROGRAM) $(objects) $(LDLIBS)

obj/%.o : %.c $(headers)
	$(CC) $(CPPFLAGS) -c -g -o $@ $<

.PHONY: setup clean

setup:
	mkdir obj
	mkdir bin

clean:
	rm $(objects)
	rm $(OUTDIR)/$(PROGRAM)

