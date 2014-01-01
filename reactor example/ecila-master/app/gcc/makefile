# output type (EXE | LIB)
OUTPUT_TYPE			:= EXE

# compile mode (DEBUG | RELEASE)
COMPILE_MODE		:= DEBUG



ifeq (FREEBSD, $(OS_PLATFORM))
OS_FLAGS			:= -DOS_FREEBSD
else
OS_FLAGS			:= -DOS_LINUX
endif


ifeq (EXE, $(OUTPUT_TYPE))
ifeq (DEBUG, $(COMPILE_MODE))
OUTPUT				:= app_d
else
OUTPUT				:= app_r 
endif
else
ifeq (DEBUG, $(COMPILE_MODE))
OUTPUT				:= libapp_d.a
else
OUTPUT				:= libapp_r.a
endif
endif



SRCDIR				:= ..
CSRCFILES			:= $(sort $(wildcard $(SRCDIR)/*.c))
CXXSRCFILES			:= $(sort $(wildcard $(SRCDIR)/*.cpp))
SRCFILES			:= $(CSRCFILES) $(CXXSRCFILES)

OBJDIR				:= ../obj
COBJFILES			:= $(subst $(SRCDIR), $(OBJDIR), $(patsubst %.c, %.o, $(CSRCFILES)))
CXXOBJFILES			:= $(subst $(SRCDIR), $(OBJDIR), $(patsubst %.cpp, %.o, $(CXXSRCFILES)))
OBJFILES			:= $(COBJFILES) $(CXXOBJFILES)
P_OBJFILES			:= $(notdir $(OBJFILES))


MYSQL_INCS			:= $(shell mysql_config --include)
MYSQL_LIBS			:= $(shell mysql_config --libs_r)
PGSQL_INCS			:= -I$(shell pg_config --includedir)
PGSQL_LIBS			:= -L$(shell pg_config --libdir) -lpq
INCS				:= -I../ -I../../ $(MYSQL_INCS) $(PGSQL_INCS)
ifeq (DEBUG, $(COMPILE_MODE))
LIBS				:= -L../../ecila/bin -lecila_d $(MYSQL_LIBS) $(PGSQL_LIBS)
else
LIBS				:= -L../../ecila/bin -lecila_r $(MYSQL_LIBS) $(PGSQL_LIBS)
endif

ifeq (DEBUG, $(COMPILE_MODE))
CFLAGS				:= -Wall -g $(OS_FLAGS) -pthread -D_REENTRANT -DUSE_DEBUG_MODE -finput-charset=UTF-8
CXXFLAGS			:= -Wall -g $(OS_FLAGS) -pthread -D_REENTRANT -DUSE_DEBUG_MODE -finput-charset=UTF-8
LDFLAGS				:= -g -lpthread
else
CFLAGS				:= -Wall -O3 $(OS_FLAGS) -pthread -D_REENTRANT -finput-charset=UTF-8
CXXFLAGS			:= -Wall -O3 $(OS_FLAGS) -pthread -D_REENTRANT -finput-charset=UTF-8
LDFLAGS				:= -lpthread
endif



TARGETDIR			:= ../bin
TARGET				:= $(TARGETDIR)/$(OUTPUT)






.PHONY: all base clean


all: $(TARGET)


base:
	mkdir -p $(OBJDIR)
	mkdir -p $(TARGETDIR)


clean:
	rm -f $(TARGETDIR)/*.*
	rm -f $(OBJDIR)/*.*

dep:
	$(CXX) -MM $(SRCFILES) > $(OBJDIR)/dependency.dep


%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $(INCS) $< -o $(OBJDIR)/$@

%.o : $(SRCDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCS) $< -o $(OBJDIR)/$@



$(TARGET) : $(P_OBJFILES)
ifeq (EXE, $(OUTPUT_TYPE))
	$(CXX) -o $@ $(OBJFILES) $(LIBS)
endif

ifeq (LIB, $(OUTPUT_TYPE))
	$(AR) $@ $(OBJFILES)
	$(RANLIB) $@
endif


$(P_OBJFILES): dep



ifeq ($(OBJDIR)/dependency.dep, $(wildcard $(OBJDIR)/dependency.dep))
include $(OBJDIR)/dependency.dep
endif

