IDIR =.
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj

LIBS=-lwiringPi

_OBJ = write_color.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS) $(ODIR)/
		$(CC) -c -o $@ $< $(CFLAGS)

%/:
	mkdir -p $@

write_color: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

all: write_color
