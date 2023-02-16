IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = struct.o
_OBJ2 = practice_1.o
_OBJ3 = practice_2.o
_OBJ4 = charptr.o
_OBJ5 = 3dmatrix.o
_OBJ6 = 3d_dynamic.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: struct practice_1 practice_1 charptr 3d_dynamic 3dmatrix
charptr : $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
3dmatrix : $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
3d_dynamic : $(_OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
struct: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
practice_1: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
practice_2: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f charptr
	rm -f struct
	rm -f practice_1
	rm -f practice_2
	rm -f 3d_dynamic
	rm -f 3dmatrix
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append         