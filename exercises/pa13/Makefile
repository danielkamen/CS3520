IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = DebugT-1.o
_OBJ2 = DebugT-2.o
_OBJ3 = DebugT-3.o
_OBJ4 = DebugT-4.o
_OBJ5 = DebugT-5.o
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: DebugT-1 DebugT-2 DebugT-3 DebugT-4 DebugT-5
DebugT-1: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
DebugT-2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
DebugT-3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
DebugT-4 : $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
DebugT-5 : $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f DebugT-1
	rm -f DebugT-2
	rm -f DebugT-3
	rm -f DebugT-4
	rm -f DebugT-5
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append         