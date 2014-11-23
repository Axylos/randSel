IDIR =../include
VERSION=c99
CC=gcc
CFLAGS=-I$(IDIR) -g -std=$(VERSION)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = randSel.h testPart.h
DEPS = $(patsbust %,$(IDIR)/%,$(_DEPS))

_OBJ = randSel.o sel.o testPart.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sel: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

test: $(OBJ)
	gcc test.c -o test $(CFLAGS) $(LIBS)
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
