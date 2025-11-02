BDIR = ./bin
IDIR = ./include
ODIR = ./obj
SDIR = ./src
OUTDIR = ./output

CC = g++
CFLAGS = -I$(IDIR) -Wall -std=c++26

# list of headers (dependencies) and rule to format them as [INCLUDE_DIR]/[HEADER]
_DEPS = cli.h color.h cxxopts.hpp gif.h image.h lodepng.h polaroidify.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# list of objects and rule to format them as [OBJECT_DIR]/[OBJECT]
_OBJ = cli.o color.o gif.o image.o lodepng.o main.o polaroidify.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# rule to make each object with corresponding named cpp file and headers as dependencies
$(ODIR)/%.o : $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# rule to make all objects and build the result as main.exe
main : $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS)

.PHONY : clean

clean:
	rm -f $(ODIR)/*.o $(OUTDIR)/*.png $(BDIR)/*.exe
