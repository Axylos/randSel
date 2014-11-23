IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = randSel.h
DEPS = $(patsbust %,$(IDIR)/%,$(_DEPS))

_OBJ = randSel.o sel.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

sel: $(OBJ)
	gcc -g -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
