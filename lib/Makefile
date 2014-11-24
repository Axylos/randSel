IDIR =../include
VERSION=c99
CC=gcc
CFLAGS=-I$(IDIR) -g -std=$(VERSION)

ODIR=obj
TDIR=tests
LDIR=../lib

LIBS=

_DEPS = randSel.h 
DEPS = $(patsbust %,$(IDIR)/%,$(_DEPS))

_T_DEPS = testPart.h 
T_DEPS = $(patsbust %,$(IDIR)/%,$(_T_DEPS))

_OBJ = randSel.o sel.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TEST_OBJ = randSel.o testPart.o test.o
TEST_OBJ = $(patsubst %,$(TDIR)/%,$(_TEST_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TDIR)/%.o: %.c $(DEPS) $(T_DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

sel: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

test: $(TEST_OBJ)
	make sel
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
clean:
	rm -f $(ODIR)/*.o $(TDIR)/*.o *~ core $(INCDIR)/*~
