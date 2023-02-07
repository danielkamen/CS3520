IDIR = .. / include
CC = g++
CFLAGS = -I$(IDIR) - g - O0

ODIR = .

LIBS = -lncurses

_DEPS =
DEPS = $(patsubst%, $(IDIR) / %, $(_DEPS))

_OBJ1 = main2.o
_OBJ2 = file2header.o
_OBJ3 = file2.o

$(ODIR) / % .o: % .cpp % .hpp $(DEPS)
$(CC) - c - o $@ $ < $(CFLAGS)

    all: main file2header file2
    main : $(_OBJ1)
    $(CC) - o $@ $ ^ $(CFLAGS) $(LIBS)
    file2header : $(_OBJ2)
    $(CC) - o $@ $ ^ $(CFLAGS) $(LIBS)
    file2 : $(_OBJ3)
    $(CC) - o $@ $ ^ $(CFLAGS) $(LIBS)
    .PHONY: clean

    clean :
rm - f * ~core $(INCDIR)/*~
rm -f main
rm -f file2
rm -f file2header
rm -f *.o

etags:
    find . -type f -iname "*.[ch]" | xargs etags --append