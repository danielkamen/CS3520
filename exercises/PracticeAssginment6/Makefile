IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0 -std=c++11

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = PA6.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

PA6: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f PA6
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append         
