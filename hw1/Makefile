IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = file1.o
_OBJ2 = file2.o
_OBJ3 = file3.o
_OBJ4 = fig05_06.o
_OBJ5 = find_and_replace.o
_OBJ6 = stats_from_paragraph.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: file1 file2 file3 fig05_06 find_and_replace stats_from_paragraph
fig05_06 : $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
find_and_replace : $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
stats_from_paragraph : $(_OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
file1: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
file2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
file3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f file1
	rm -f file2
	rm -f file3
	rm -f fig05_05
	rm -f find_and_replace
	rm -f stats_from_paragraph
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append         
