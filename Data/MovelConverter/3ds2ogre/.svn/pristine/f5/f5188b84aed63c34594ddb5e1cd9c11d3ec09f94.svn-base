CXXFLAGS=-I$(OGRE_HOME)/include/OGRE \
	-DEXT_HASH \
	-I../3dsftk3/INC

LIBS=-g -L$(OGRE_HOME)/lib \
     -Wl,--rpath -Wl,$(OGRE_HOME)/lib -lOgreMain \
     -L../3dsftk3/lib -lftk

TARGETS = 3ds2mesh

all: $(TARGETS)

$(TARGETS): $$@.o
	$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

clean:
	rm -f *.o $(TARGETS) *\~ *.log
