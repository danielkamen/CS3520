IDIR = .. / include
CC = g++
CFLAGS = -I$(IDIR) - g - O0

ODIR = .

LIBS = -lncurses

_DEPS =
DEPS = $(patsubst%, $(IDIR) / %, $(_DEPS))

_OBJ1 = file1header.o
_OBJ2 = file2.o
_OBJ3 = Main.o

$(ODIR) / % .o: % .cpp % .hpp $(DEPS)
$(CC) - c - o $@ $ < $(CFLAGS)

    all: Main file1header file1
    main : $(_OBJ1)
    $(CC) - o $@ $ ^ $(CFLAGS) $(LIBS)
    file2header : $(_OBJ2)
    $(CC) - o $@ $ ^ $(CFLAGS) $(LIBS)
    file2 : $(_OBJ2)
    $(CC) - o $@ $ ^ $(CFLAGS) $(LIBS)
    .PHONY: clean

    clean :
rm - f * ~core $(INCDIR)/*~
rm -f Main
rm -f file1
rm -f file1header
rm -f *.o

etags:
    find . -type f -iname "*.[ch]" | xargs etags --append