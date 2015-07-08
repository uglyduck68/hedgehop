# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PENTIUM4gnu_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := E:/workspace
PRJ_ROOT_DIR := E:/home/mcp/99.etc/PocoLib



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = -DPOCO_VXWORKS -DVXWORKS_VERSION_MAJOR=6 -DVXWORKS_VERSION_MINOR=8 -Di386
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = pentium
CPU = PENTIUM4
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4
LIBPATH = 
LIBS = -lstdc++
VSB_DIR = $(WIND_BASE)/target/lib

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/h/sys -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(PRJ_ROOT_DIR)/Foundation/include -I$(PRJ_ROOT_DIR)/JSON/include -I$(PRJ_ROOT_DIR)/Net/include -I$(PRJ_ROOT_DIR)/Util/include -I$(PRJ_ROOT_DIR)/XML/include 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2   
DEBUGFLAGS_C++-Compiler = -O2   
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2   
endif


#Project Targets
PROJECT_TARGETS = libPocoLib/$(MODE_DIR)/libPocoLib.a


#Rules

# libPocoLib
ifeq ($(DEBUG_MODE),1)
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2   
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2   
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
libPocoLib/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2   
endif
libPocoLib/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/h/sys -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(PRJ_ROOT_DIR)/Foundation/include -I$(PRJ_ROOT_DIR)/JSON/include -I$(PRJ_ROOT_DIR)/Net/include -I$(PRJ_ROOT_DIR)/Util/include -I$(PRJ_ROOT_DIR)/XML/include 
libPocoLib/$(MODE_DIR)/% : IDE_LIBRARIES = 
libPocoLib/$(MODE_DIR)/% : PROJECT_TYPE = RTP
libPocoLib/$(MODE_DIR)/% : DEFINES = -DPOCO_VXWORKS -DVXWORKS_VERSION_MAJOR=6 -DVXWORKS_VERSION_MINOR=8 -Di386
libPocoLib/$(MODE_DIR)/% : DO_STRIP = 0
libPocoLib/$(MODE_DIR)/% : EXPAND_DBG = 0
libPocoLib/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
libPocoLib/$(MODE_DIR)/% : CPU = PENTIUM4
libPocoLib/$(MODE_DIR)/% : TOOL_FAMILY = gnu
libPocoLib/$(MODE_DIR)/% : TOOL = gnu
libPocoLib/$(MODE_DIR)/% : TOOL_PATH = 
libPocoLib/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4
libPocoLib/$(MODE_DIR)/% : LIBPATH = 
libPocoLib/$(MODE_DIR)/% : LIBS = -lstdc++
libPocoLib/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
libPocoLib/$(MODE_DIR)/% : OBJ_DIR := libPocoLib/$(MODE_DIR)

libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ASCIIEncoding.o : $(PRJ_ROOT_DIR)/Foundation/src/ASCIIEncoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AbstractObserver.o : $(PRJ_ROOT_DIR)/Foundation/src/AbstractObserver.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ActiveDispatcher.o : $(PRJ_ROOT_DIR)/Foundation/src/ActiveDispatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ArchiveStrategy.o : $(PRJ_ROOT_DIR)/Foundation/src/ArchiveStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Ascii.o : $(PRJ_ROOT_DIR)/Foundation/src/Ascii.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AsyncChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/AsyncChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AtomicCounter.o : $(PRJ_ROOT_DIR)/Foundation/src/AtomicCounter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base32Decoder.o : $(PRJ_ROOT_DIR)/Foundation/src/Base32Decoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base32Encoder.o : $(PRJ_ROOT_DIR)/Foundation/src/Base32Encoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base64Decoder.o : $(PRJ_ROOT_DIR)/Foundation/src/Base64Decoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base64Encoder.o : $(PRJ_ROOT_DIR)/Foundation/src/Base64Encoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/BinaryReader.o : $(PRJ_ROOT_DIR)/Foundation/src/BinaryReader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/BinaryWriter.o : $(PRJ_ROOT_DIR)/Foundation/src/BinaryWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Bugcheck.o : $(PRJ_ROOT_DIR)/Foundation/src/Bugcheck.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ByteOrder.o : $(PRJ_ROOT_DIR)/Foundation/src/ByteOrder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Channel.o : $(PRJ_ROOT_DIR)/Foundation/src/Channel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Checksum.o : $(PRJ_ROOT_DIR)/Foundation/src/Checksum.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Clock.o : $(PRJ_ROOT_DIR)/Foundation/src/Clock.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Condition.o : $(PRJ_ROOT_DIR)/Foundation/src/Condition.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Configurable.o : $(PRJ_ROOT_DIR)/Foundation/src/Configurable.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ConsoleChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/ConsoleChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/CountingStream.o : $(PRJ_ROOT_DIR)/Foundation/src/CountingStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTime.o : $(PRJ_ROOT_DIR)/Foundation/src/DateTime.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeFormat.o : $(PRJ_ROOT_DIR)/Foundation/src/DateTimeFormat.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeFormatter.o : $(PRJ_ROOT_DIR)/Foundation/src/DateTimeFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeParser.o : $(PRJ_ROOT_DIR)/Foundation/src/DateTimeParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Debugger.o : $(PRJ_ROOT_DIR)/Foundation/src/Debugger.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DeflatingStream.o : $(PRJ_ROOT_DIR)/Foundation/src/DeflatingStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DigestEngine.o : $(PRJ_ROOT_DIR)/Foundation/src/DigestEngine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DigestStream.o : $(PRJ_ROOT_DIR)/Foundation/src/DigestStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIterator.o : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIteratorStrategy.o : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryIteratorStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIterator_UNIX.o : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryIterator_UNIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryWatcher.o : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryWatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Environment.o : $(PRJ_ROOT_DIR)/Foundation/src/Environment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Environment_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Environment_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Error.o : $(PRJ_ROOT_DIR)/Foundation/src/Error.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ErrorHandler.o : $(PRJ_ROOT_DIR)/Foundation/src/ErrorHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event.o : $(PRJ_ROOT_DIR)/Foundation/src/Event.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/EventArgs.o : $(PRJ_ROOT_DIR)/Foundation/src/EventArgs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/Event_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Event_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Exception.o : $(PRJ_ROOT_DIR)/Foundation/src/Exception.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FIFOBufferStream.o : $(PRJ_ROOT_DIR)/Foundation/src/FIFOBufferStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FPEnvironment.o : $(PRJ_ROOT_DIR)/Foundation/src/FPEnvironment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FPEnvironment_C99.o : $(PRJ_ROOT_DIR)/Foundation/src/FPEnvironment_C99.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/File.o : $(PRJ_ROOT_DIR)/Foundation/src/File.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/FileChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStream.o : $(PRJ_ROOT_DIR)/Foundation/src/FileStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStreamFactory.o : $(PRJ_ROOT_DIR)/Foundation/src/FileStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStream_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/FileStream_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/File_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/File_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Format.o : $(PRJ_ROOT_DIR)/Foundation/src/Format.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Formatter.o : $(PRJ_ROOT_DIR)/Foundation/src/Formatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FormattingChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/FormattingChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Glob.o : $(PRJ_ROOT_DIR)/Foundation/src/Glob.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Hash.o : $(PRJ_ROOT_DIR)/Foundation/src/Hash.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HashStatistic.o : $(PRJ_ROOT_DIR)/Foundation/src/HashStatistic.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HexBinaryDecoder.o : $(PRJ_ROOT_DIR)/Foundation/src/HexBinaryDecoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HexBinaryEncoder.o : $(PRJ_ROOT_DIR)/Foundation/src/HexBinaryEncoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/InflatingStream.o : $(PRJ_ROOT_DIR)/Foundation/src/InflatingStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin1Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/Latin1Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin2Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/Latin2Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin9Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/Latin9Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LineEndingConverter.o : $(PRJ_ROOT_DIR)/Foundation/src/LineEndingConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LocalDateTime.o : $(PRJ_ROOT_DIR)/Foundation/src/LocalDateTime.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogFile.o : $(PRJ_ROOT_DIR)/Foundation/src/LogFile.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogFile_STD.o : $(PRJ_ROOT_DIR)/Foundation/src/LogFile_STD.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogStream.o : $(PRJ_ROOT_DIR)/Foundation/src/LogStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Logger.o : $(PRJ_ROOT_DIR)/Foundation/src/Logger.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LoggingFactory.o : $(PRJ_ROOT_DIR)/Foundation/src/LoggingFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LoggingRegistry.o : $(PRJ_ROOT_DIR)/Foundation/src/LoggingRegistry.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MD4Engine.o : $(PRJ_ROOT_DIR)/Foundation/src/MD4Engine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MD5Engine.o : $(PRJ_ROOT_DIR)/Foundation/src/MD5Engine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Manifest.o : $(PRJ_ROOT_DIR)/Foundation/src/Manifest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MemoryPool.o : $(PRJ_ROOT_DIR)/Foundation/src/MemoryPool.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MemoryStream.o : $(PRJ_ROOT_DIR)/Foundation/src/MemoryStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Message.o : $(PRJ_ROOT_DIR)/Foundation/src/Message.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex.o : $(PRJ_ROOT_DIR)/Foundation/src/Mutex.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/Mutex_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Mutex_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent.o : $(PRJ_ROOT_DIR)/Foundation/src/NamedEvent.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent_Android.o : $(PRJ_ROOT_DIR)/Foundation/src/NamedEvent_Android.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent_UNIX.o : $(PRJ_ROOT_DIR)/Foundation/src/NamedEvent_UNIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex.o : $(PRJ_ROOT_DIR)/Foundation/src/NamedMutex.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex_Android.o : $(PRJ_ROOT_DIR)/Foundation/src/NamedMutex_Android.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex_UNIX.o : $(PRJ_ROOT_DIR)/Foundation/src/NamedMutex_UNIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NestedDiagnosticContext.o : $(PRJ_ROOT_DIR)/Foundation/src/NestedDiagnosticContext.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Notification.o : $(PRJ_ROOT_DIR)/Foundation/src/Notification.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NotificationCenter.o : $(PRJ_ROOT_DIR)/Foundation/src/NotificationCenter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NotificationQueue.o : $(PRJ_ROOT_DIR)/Foundation/src/NotificationQueue.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NullChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/NullChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NullStream.o : $(PRJ_ROOT_DIR)/Foundation/src/NullStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumberFormatter.o : $(PRJ_ROOT_DIR)/Foundation/src/NumberFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumberParser.o : $(PRJ_ROOT_DIR)/Foundation/src/NumberParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumericString.o : $(PRJ_ROOT_DIR)/Foundation/src/NumericString.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Path.o : $(PRJ_ROOT_DIR)/Foundation/src/Path.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Path_UNIX.o : $(PRJ_ROOT_DIR)/Foundation/src/Path_UNIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PatternFormatter.o : $(PRJ_ROOT_DIR)/Foundation/src/PatternFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Pipe.o : $(PRJ_ROOT_DIR)/Foundation/src/Pipe.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl.o : $(PRJ_ROOT_DIR)/Foundation/src/PipeImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl_DUMMY.o : $(PRJ_ROOT_DIR)/Foundation/src/PipeImpl_DUMMY.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/PipeImpl_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeStream.o : $(PRJ_ROOT_DIR)/Foundation/src/PipeStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PriorityNotificationQueue.o : $(PRJ_ROOT_DIR)/Foundation/src/PriorityNotificationQueue.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Process.o : $(PRJ_ROOT_DIR)/Foundation/src/Process.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Process_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Process_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PurgeStrategy.o : $(PRJ_ROOT_DIR)/Foundation/src/PurgeStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock.o : $(PRJ_ROOT_DIR)/Foundation/src/RWLock.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock_Android.o : $(PRJ_ROOT_DIR)/Foundation/src/RWLock_Android.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/RWLock_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Random.o : $(PRJ_ROOT_DIR)/Foundation/src/Random.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RandomStream.o : $(PRJ_ROOT_DIR)/Foundation/src/RandomStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RefCountedObject.o : $(PRJ_ROOT_DIR)/Foundation/src/RefCountedObject.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RegularExpression.o : $(PRJ_ROOT_DIR)/Foundation/src/RegularExpression.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RotateStrategy.o : $(PRJ_ROOT_DIR)/Foundation/src/RotateStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Runnable.o : $(PRJ_ROOT_DIR)/Foundation/src/Runnable.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SHA1Engine.o : $(PRJ_ROOT_DIR)/Foundation/src/SHA1Engine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore.o : $(PRJ_ROOT_DIR)/Foundation/src/Semaphore.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/Semaphore_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Semaphore_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory.o : $(PRJ_ROOT_DIR)/Foundation/src/SharedMemory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory_DUMMY.o : $(PRJ_ROOT_DIR)/Foundation/src/SharedMemory_DUMMY.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/SharedMemory_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SignalHandler.o : $(PRJ_ROOT_DIR)/Foundation/src/SignalHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SimpleFileChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/SimpleFileChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SortedDirectoryIterator.o : $(PRJ_ROOT_DIR)/Foundation/src/SortedDirectoryIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SplitterChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/SplitterChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Stopwatch.o : $(PRJ_ROOT_DIR)/Foundation/src/Stopwatch.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/StreamChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamConverter.o : $(PRJ_ROOT_DIR)/Foundation/src/StreamConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamCopier.o : $(PRJ_ROOT_DIR)/Foundation/src/StreamCopier.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamTokenizer.o : $(PRJ_ROOT_DIR)/Foundation/src/StreamTokenizer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/String.o : $(PRJ_ROOT_DIR)/Foundation/src/String.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StringTokenizer.o : $(PRJ_ROOT_DIR)/Foundation/src/StringTokenizer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SynchronizedObject.o : $(PRJ_ROOT_DIR)/Foundation/src/SynchronizedObject.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SyslogChannel.o : $(PRJ_ROOT_DIR)/Foundation/src/SyslogChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Task.o : $(PRJ_ROOT_DIR)/Foundation/src/Task.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TaskManager.o : $(PRJ_ROOT_DIR)/Foundation/src/TaskManager.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TaskNotification.o : $(PRJ_ROOT_DIR)/Foundation/src/TaskNotification.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TeeStream.o : $(PRJ_ROOT_DIR)/Foundation/src/TeeStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TemporaryFile.o : $(PRJ_ROOT_DIR)/Foundation/src/TemporaryFile.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextBufferIterator.o : $(PRJ_ROOT_DIR)/Foundation/src/TextBufferIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextConverter.o : $(PRJ_ROOT_DIR)/Foundation/src/TextConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextEncoding.o : $(PRJ_ROOT_DIR)/Foundation/src/TextEncoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextIterator.o : $(PRJ_ROOT_DIR)/Foundation/src/TextIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread.o : $(PRJ_ROOT_DIR)/Foundation/src/Thread.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadLocal.o : $(PRJ_ROOT_DIR)/Foundation/src/ThreadLocal.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadPool.o : $(PRJ_ROOT_DIR)/Foundation/src/ThreadPool.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadTarget.o : $(PRJ_ROOT_DIR)/Foundation/src/ThreadTarget.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread_POSIX.o : $(PRJ_ROOT_DIR)/Foundation/src/Thread_POSIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Thread_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TimedNotificationQueue.o : $(PRJ_ROOT_DIR)/Foundation/src/TimedNotificationQueue.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timer.o : $(PRJ_ROOT_DIR)/Foundation/src/Timer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timespan.o : $(PRJ_ROOT_DIR)/Foundation/src/Timespan.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timestamp.o : $(PRJ_ROOT_DIR)/Foundation/src/Timestamp.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone.o : $(PRJ_ROOT_DIR)/Foundation/src/Timezone.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone_UNIX.o : $(PRJ_ROOT_DIR)/Foundation/src/Timezone_UNIX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone_VX.o : $(PRJ_ROOT_DIR)/Foundation/src/Timezone_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Token.o : $(PRJ_ROOT_DIR)/Foundation/src/Token.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URI.o : $(PRJ_ROOT_DIR)/Foundation/src/URI.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URIStreamFactory.o : $(PRJ_ROOT_DIR)/Foundation/src/URIStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URIStreamOpener.o : $(PRJ_ROOT_DIR)/Foundation/src/URIStreamOpener.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF16Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/UTF16Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF32Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/UTF32Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF8Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/UTF8Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF8String.o : $(PRJ_ROOT_DIR)/Foundation/src/UTF8String.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UUID.o : $(PRJ_ROOT_DIR)/Foundation/src/UUID.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UUIDGenerator.o : $(PRJ_ROOT_DIR)/Foundation/src/UUIDGenerator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Unicode.o : $(PRJ_ROOT_DIR)/Foundation/src/Unicode.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UnicodeConverter.o : $(PRJ_ROOT_DIR)/Foundation/src/UnicodeConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Var.o : $(PRJ_ROOT_DIR)/Foundation/src/Var.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/VarHolder.o : $(PRJ_ROOT_DIR)/Foundation/src/VarHolder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/VarIterator.o : $(PRJ_ROOT_DIR)/Foundation/src/VarIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Void.o : $(PRJ_ROOT_DIR)/Foundation/src/Void.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1250Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/Windows1250Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1251Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/Windows1251Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1252Encoding.o : $(PRJ_ROOT_DIR)/Foundation/src/Windows1252Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/adler32.o : $(PRJ_ROOT_DIR)/Foundation/src/adler32.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/bignum-dtoa.o : $(PRJ_ROOT_DIR)/Foundation/src/bignum-dtoa.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/bignum.o : $(PRJ_ROOT_DIR)/Foundation/src/bignum.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/cached-powers.o : $(PRJ_ROOT_DIR)/Foundation/src/cached-powers.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/compress.o : $(PRJ_ROOT_DIR)/Foundation/src/compress.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/crc32.o : $(PRJ_ROOT_DIR)/Foundation/src/crc32.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/deflate.o : $(PRJ_ROOT_DIR)/Foundation/src/deflate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/diy-fp.o : $(PRJ_ROOT_DIR)/Foundation/src/diy-fp.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/double-conversion.o : $(PRJ_ROOT_DIR)/Foundation/src/double-conversion.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/fast-dtoa.o : $(PRJ_ROOT_DIR)/Foundation/src/fast-dtoa.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/fixed-dtoa.o : $(PRJ_ROOT_DIR)/Foundation/src/fixed-dtoa.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/infback.o : $(PRJ_ROOT_DIR)/Foundation/src/infback.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inffast.o : $(PRJ_ROOT_DIR)/Foundation/src/inffast.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inflate.o : $(PRJ_ROOT_DIR)/Foundation/src/inflate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inftrees.o : $(PRJ_ROOT_DIR)/Foundation/src/inftrees.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_byte_order.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_byte_order.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_chartables.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_chartables.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_compile.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_compile.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_config.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_config.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_dfa_exec.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_dfa_exec.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_exec.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_exec.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_fullinfo.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_fullinfo.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_get.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_get.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_globals.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_globals.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_jit_compile.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_jit_compile.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_maketables.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_maketables.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_newline.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_newline.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_ord2utf8.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_ord2utf8.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_refcount.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_refcount.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_string_utils.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_string_utils.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_study.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_study.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_tables.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_tables.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_ucd.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_ucd.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_valid_utf8.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_valid_utf8.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_version.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_version.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_xclass.o : $(PRJ_ROOT_DIR)/Foundation/src/pcre_xclass.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/strtod.o : $(PRJ_ROOT_DIR)/Foundation/src/strtod.cc
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/trees.o : $(PRJ_ROOT_DIR)/Foundation/src/trees.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/zutil.o : $(PRJ_ROOT_DIR)/Foundation/src/zutil.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Array.o : $(PRJ_ROOT_DIR)/JSON/src/Array.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Handler.o : $(PRJ_ROOT_DIR)/JSON/src/Handler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/JSONException.o : $(PRJ_ROOT_DIR)/JSON/src/JSONException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Object.o : $(PRJ_ROOT_DIR)/JSON/src/Object.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/ParseHandler.o : $(PRJ_ROOT_DIR)/JSON/src/ParseHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Parser.o : $(PRJ_ROOT_DIR)/JSON/src/Parser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/PrintHandler.o : $(PRJ_ROOT_DIR)/JSON/src/PrintHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Query.o : $(PRJ_ROOT_DIR)/JSON/src/Query.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Stringifier.o : $(PRJ_ROOT_DIR)/JSON/src/Stringifier.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Template.o : $(PRJ_ROOT_DIR)/JSON/src/Template.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/TemplateCache.o : $(PRJ_ROOT_DIR)/JSON/src/TemplateCache.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/AbstractHTTPRequestHandler.o : $(PRJ_ROOT_DIR)/Net/src/AbstractHTTPRequestHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DNS.o : $(PRJ_ROOT_DIR)/Net/src/DNS.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DatagramSocket.o : $(PRJ_ROOT_DIR)/Net/src/DatagramSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DatagramSocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/DatagramSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DialogSocket.o : $(PRJ_ROOT_DIR)/Net/src/DialogSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FTPClientSession.o : $(PRJ_ROOT_DIR)/Net/src/FTPClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FTPStreamFactory.o : $(PRJ_ROOT_DIR)/Net/src/FTPStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FilePartSource.o : $(PRJ_ROOT_DIR)/Net/src/FilePartSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTMLForm.o : $(PRJ_ROOT_DIR)/Net/src/HTMLForm.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPAuthenticationParams.o : $(PRJ_ROOT_DIR)/Net/src/HTTPAuthenticationParams.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPBasicCredentials.o : $(PRJ_ROOT_DIR)/Net/src/HTTPBasicCredentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPBufferAllocator.o : $(PRJ_ROOT_DIR)/Net/src/HTTPBufferAllocator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPChunkedStream.o : $(PRJ_ROOT_DIR)/Net/src/HTTPChunkedStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPClientSession.o : $(PRJ_ROOT_DIR)/Net/src/HTTPClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPCookie.o : $(PRJ_ROOT_DIR)/Net/src/HTTPCookie.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPCredentials.o : $(PRJ_ROOT_DIR)/Net/src/HTTPCredentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPDigestCredentials.o : $(PRJ_ROOT_DIR)/Net/src/HTTPDigestCredentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPFixedLengthStream.o : $(PRJ_ROOT_DIR)/Net/src/HTTPFixedLengthStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPHeaderStream.o : $(PRJ_ROOT_DIR)/Net/src/HTTPHeaderStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPIOStream.o : $(PRJ_ROOT_DIR)/Net/src/HTTPIOStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPMessage.o : $(PRJ_ROOT_DIR)/Net/src/HTTPMessage.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequest.o : $(PRJ_ROOT_DIR)/Net/src/HTTPRequest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequestHandler.o : $(PRJ_ROOT_DIR)/Net/src/HTTPRequestHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequestHandlerFactory.o : $(PRJ_ROOT_DIR)/Net/src/HTTPRequestHandlerFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPResponse.o : $(PRJ_ROOT_DIR)/Net/src/HTTPResponse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServer.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerConnection.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerConnection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerConnectionFactory.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerConnectionFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerParams.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerParams.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerRequest.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerRequest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerRequestImpl.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerRequestImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerResponse.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerResponse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerResponseImpl.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerResponseImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerSession.o : $(PRJ_ROOT_DIR)/Net/src/HTTPServerSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSession.o : $(PRJ_ROOT_DIR)/Net/src/HTTPSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSessionFactory.o : $(PRJ_ROOT_DIR)/Net/src/HTTPSessionFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSessionInstantiator.o : $(PRJ_ROOT_DIR)/Net/src/HTTPSessionInstantiator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPStream.o : $(PRJ_ROOT_DIR)/Net/src/HTTPStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPStreamFactory.o : $(PRJ_ROOT_DIR)/Net/src/HTTPStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HostEntry.o : $(PRJ_ROOT_DIR)/Net/src/HostEntry.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPClient.o : $(PRJ_ROOT_DIR)/Net/src/ICMPClient.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPEventArgs.o : $(PRJ_ROOT_DIR)/Net/src/ICMPEventArgs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPPacket.o : $(PRJ_ROOT_DIR)/Net/src/ICMPPacket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPPacketImpl.o : $(PRJ_ROOT_DIR)/Net/src/ICMPPacketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPSocket.o : $(PRJ_ROOT_DIR)/Net/src/ICMPSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPSocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/ICMPSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPv4PacketImpl.o : $(PRJ_ROOT_DIR)/Net/src/ICMPv4PacketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/IPAddress.o : $(PRJ_ROOT_DIR)/Net/src/IPAddress.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/IPAddressImpl.o : $(PRJ_ROOT_DIR)/Net/src/IPAddressImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailMessage.o : $(PRJ_ROOT_DIR)/Net/src/MailMessage.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailRecipient.o : $(PRJ_ROOT_DIR)/Net/src/MailRecipient.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailStream.o : $(PRJ_ROOT_DIR)/Net/src/MailStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MediaType.o : $(PRJ_ROOT_DIR)/Net/src/MediaType.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MessageHeader.o : $(PRJ_ROOT_DIR)/Net/src/MessageHeader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MulticastSocket.o : $(PRJ_ROOT_DIR)/Net/src/MulticastSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MultipartReader.o : $(PRJ_ROOT_DIR)/Net/src/MultipartReader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MultipartWriter.o : $(PRJ_ROOT_DIR)/Net/src/MultipartWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPClient.o : $(PRJ_ROOT_DIR)/Net/src/NTPClient.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPEventArgs.o : $(PRJ_ROOT_DIR)/Net/src/NTPEventArgs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPPacket.o : $(PRJ_ROOT_DIR)/Net/src/NTPPacket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NameValueCollection.o : $(PRJ_ROOT_DIR)/Net/src/NameValueCollection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/Net.o : $(PRJ_ROOT_DIR)/Net/src/Net.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NetException.o : $(PRJ_ROOT_DIR)/Net/src/NetException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NetworkInterface.o : $(PRJ_ROOT_DIR)/Net/src/NetworkInterface.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NullPartHandler.o : $(PRJ_ROOT_DIR)/Net/src/NullPartHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/OAuth10Credentials.o : $(PRJ_ROOT_DIR)/Net/src/OAuth10Credentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/OAuth20Credentials.o : $(PRJ_ROOT_DIR)/Net/src/OAuth20Credentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/POP3ClientSession.o : $(PRJ_ROOT_DIR)/Net/src/POP3ClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartHandler.o : $(PRJ_ROOT_DIR)/Net/src/PartHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartSource.o : $(PRJ_ROOT_DIR)/Net/src/PartSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartStore.o : $(PRJ_ROOT_DIR)/Net/src/PartStore.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/QuotedPrintableDecoder.o : $(PRJ_ROOT_DIR)/Net/src/QuotedPrintableDecoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/QuotedPrintableEncoder.o : $(PRJ_ROOT_DIR)/Net/src/QuotedPrintableEncoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RawSocket.o : $(PRJ_ROOT_DIR)/Net/src/RawSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RawSocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/RawSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RemoteSyslogChannel.o : $(PRJ_ROOT_DIR)/Net/src/RemoteSyslogChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RemoteSyslogListener.o : $(PRJ_ROOT_DIR)/Net/src/RemoteSyslogListener.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SMTPChannel.o : $(PRJ_ROOT_DIR)/Net/src/SMTPChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SMTPClientSession.o : $(PRJ_ROOT_DIR)/Net/src/SMTPClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ServerSocket.o : $(PRJ_ROOT_DIR)/Net/src/ServerSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ServerSocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/ServerSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/Socket.o : $(PRJ_ROOT_DIR)/Net/src/Socket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketAddress.o : $(PRJ_ROOT_DIR)/Net/src/SocketAddress.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketAddressImpl.o : $(PRJ_ROOT_DIR)/Net/src/SocketAddressImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/SocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketNotification.o : $(PRJ_ROOT_DIR)/Net/src/SocketNotification.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketNotifier.o : $(PRJ_ROOT_DIR)/Net/src/SocketNotifier.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketReactor.o : $(PRJ_ROOT_DIR)/Net/src/SocketReactor.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketStream.o : $(PRJ_ROOT_DIR)/Net/src/SocketStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StreamSocket.o : $(PRJ_ROOT_DIR)/Net/src/StreamSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StreamSocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/StreamSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StringPartSource.o : $(PRJ_ROOT_DIR)/Net/src/StringPartSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServer.o : $(PRJ_ROOT_DIR)/Net/src/TCPServer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerConnection.o : $(PRJ_ROOT_DIR)/Net/src/TCPServerConnection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerConnectionFactory.o : $(PRJ_ROOT_DIR)/Net/src/TCPServerConnectionFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerDispatcher.o : $(PRJ_ROOT_DIR)/Net/src/TCPServerDispatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerParams.o : $(PRJ_ROOT_DIR)/Net/src/TCPServerParams.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/WebSocket.o : $(PRJ_ROOT_DIR)/Net/src/WebSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/WebSocketImpl.o : $(PRJ_ROOT_DIR)/Net/src/WebSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/AbstractConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/AbstractConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Application.o : $(PRJ_ROOT_DIR)/Util/src/Application.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ConfigurationMapper.o : $(PRJ_ROOT_DIR)/Util/src/ConfigurationMapper.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ConfigurationView.o : $(PRJ_ROOT_DIR)/Util/src/ConfigurationView.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/FilesystemConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/FilesystemConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/HelpFormatter.o : $(PRJ_ROOT_DIR)/Util/src/HelpFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/IniFileConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/IniFileConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/IntValidator.o : $(PRJ_ROOT_DIR)/Util/src/IntValidator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/JSONConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/JSONConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LayeredConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/LayeredConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LoggingConfigurator.o : $(PRJ_ROOT_DIR)/Util/src/LoggingConfigurator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LoggingSubsystem.o : $(PRJ_ROOT_DIR)/Util/src/LoggingSubsystem.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/MapConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/MapConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Option.o : $(PRJ_ROOT_DIR)/Util/src/Option.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionCallback.o : $(PRJ_ROOT_DIR)/Util/src/OptionCallback.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionException.o : $(PRJ_ROOT_DIR)/Util/src/OptionException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionProcessor.o : $(PRJ_ROOT_DIR)/Util/src/OptionProcessor.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionSet.o : $(PRJ_ROOT_DIR)/Util/src/OptionSet.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/PropertyFileConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/PropertyFileConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/RegExpValidator.o : $(PRJ_ROOT_DIR)/Util/src/RegExpValidator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ServerApplication.o : $(PRJ_ROOT_DIR)/Util/src/ServerApplication.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Subsystem.o : $(PRJ_ROOT_DIR)/Util/src/Subsystem.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/SystemConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/SystemConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Timer.o : $(PRJ_ROOT_DIR)/Util/src/Timer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/TimerTask.o : $(PRJ_ROOT_DIR)/Util/src/TimerTask.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Validator.o : $(PRJ_ROOT_DIR)/Util/src/Validator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/XMLConfiguration.o : $(PRJ_ROOT_DIR)/Util/src/XMLConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AbstractContainerNode.o : $(PRJ_ROOT_DIR)/XML/src/AbstractContainerNode.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AbstractNode.o : $(PRJ_ROOT_DIR)/XML/src/AbstractNode.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Attr.o : $(PRJ_ROOT_DIR)/XML/src/Attr.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AttrMap.o : $(PRJ_ROOT_DIR)/XML/src/AttrMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Attributes.o : $(PRJ_ROOT_DIR)/XML/src/Attributes.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AttributesImpl.o : $(PRJ_ROOT_DIR)/XML/src/AttributesImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/CDATASection.o : $(PRJ_ROOT_DIR)/XML/src/CDATASection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/CharacterData.o : $(PRJ_ROOT_DIR)/XML/src/CharacterData.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ChildNodesList.o : $(PRJ_ROOT_DIR)/XML/src/ChildNodesList.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Comment.o : $(PRJ_ROOT_DIR)/XML/src/Comment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ContentHandler.o : $(PRJ_ROOT_DIR)/XML/src/ContentHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMBuilder.o : $(PRJ_ROOT_DIR)/XML/src/DOMBuilder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMException.o : $(PRJ_ROOT_DIR)/XML/src/DOMException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMImplementation.o : $(PRJ_ROOT_DIR)/XML/src/DOMImplementation.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMObject.o : $(PRJ_ROOT_DIR)/XML/src/DOMObject.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMParser.o : $(PRJ_ROOT_DIR)/XML/src/DOMParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMSerializer.o : $(PRJ_ROOT_DIR)/XML/src/DOMSerializer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMWriter.o : $(PRJ_ROOT_DIR)/XML/src/DOMWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DTDHandler.o : $(PRJ_ROOT_DIR)/XML/src/DTDHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DTDMap.o : $(PRJ_ROOT_DIR)/XML/src/DTDMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DeclHandler.o : $(PRJ_ROOT_DIR)/XML/src/DeclHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DefaultHandler.o : $(PRJ_ROOT_DIR)/XML/src/DefaultHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Document.o : $(PRJ_ROOT_DIR)/XML/src/Document.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentEvent.o : $(PRJ_ROOT_DIR)/XML/src/DocumentEvent.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentFragment.o : $(PRJ_ROOT_DIR)/XML/src/DocumentFragment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentType.o : $(PRJ_ROOT_DIR)/XML/src/DocumentType.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Element.o : $(PRJ_ROOT_DIR)/XML/src/Element.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ElementsByTagNameList.o : $(PRJ_ROOT_DIR)/XML/src/ElementsByTagNameList.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Entity.o : $(PRJ_ROOT_DIR)/XML/src/Entity.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityReference.o : $(PRJ_ROOT_DIR)/XML/src/EntityReference.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityResolver.o : $(PRJ_ROOT_DIR)/XML/src/EntityResolver.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityResolverImpl.o : $(PRJ_ROOT_DIR)/XML/src/EntityResolverImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ErrorHandler.o : $(PRJ_ROOT_DIR)/XML/src/ErrorHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Event.o : $(PRJ_ROOT_DIR)/XML/src/Event.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventDispatcher.o : $(PRJ_ROOT_DIR)/XML/src/EventDispatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventException.o : $(PRJ_ROOT_DIR)/XML/src/EventException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventListener.o : $(PRJ_ROOT_DIR)/XML/src/EventListener.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventTarget.o : $(PRJ_ROOT_DIR)/XML/src/EventTarget.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/InputSource.o : $(PRJ_ROOT_DIR)/XML/src/InputSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/LexicalHandler.o : $(PRJ_ROOT_DIR)/XML/src/LexicalHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Locator.o : $(PRJ_ROOT_DIR)/XML/src/Locator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/LocatorImpl.o : $(PRJ_ROOT_DIR)/XML/src/LocatorImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/MutationEvent.o : $(PRJ_ROOT_DIR)/XML/src/MutationEvent.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Name.o : $(PRJ_ROOT_DIR)/XML/src/Name.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamePool.o : $(PRJ_ROOT_DIR)/XML/src/NamePool.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamedNodeMap.o : $(PRJ_ROOT_DIR)/XML/src/NamedNodeMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamespaceStrategy.o : $(PRJ_ROOT_DIR)/XML/src/NamespaceStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamespaceSupport.o : $(PRJ_ROOT_DIR)/XML/src/NamespaceSupport.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Node.o : $(PRJ_ROOT_DIR)/XML/src/Node.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeAppender.o : $(PRJ_ROOT_DIR)/XML/src/NodeAppender.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeFilter.o : $(PRJ_ROOT_DIR)/XML/src/NodeFilter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeIterator.o : $(PRJ_ROOT_DIR)/XML/src/NodeIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeList.o : $(PRJ_ROOT_DIR)/XML/src/NodeList.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Notation.o : $(PRJ_ROOT_DIR)/XML/src/Notation.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ParserEngine.o : $(PRJ_ROOT_DIR)/XML/src/ParserEngine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ProcessingInstruction.o : $(PRJ_ROOT_DIR)/XML/src/ProcessingInstruction.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/SAXException.o : $(PRJ_ROOT_DIR)/XML/src/SAXException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/SAXParser.o : $(PRJ_ROOT_DIR)/XML/src/SAXParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Text.o : $(PRJ_ROOT_DIR)/XML/src/Text.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/TreeWalker.o : $(PRJ_ROOT_DIR)/XML/src/TreeWalker.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/WhitespaceFilter.o : $(PRJ_ROOT_DIR)/XML/src/WhitespaceFilter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLException.o : $(PRJ_ROOT_DIR)/XML/src/XMLException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLFilter.o : $(PRJ_ROOT_DIR)/XML/src/XMLFilter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLFilterImpl.o : $(PRJ_ROOT_DIR)/XML/src/XMLFilterImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLReader.o : $(PRJ_ROOT_DIR)/XML/src/XMLReader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLString.o : $(PRJ_ROOT_DIR)/XML/src/XMLString.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLWriter.o : $(PRJ_ROOT_DIR)/XML/src/XMLWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmlparse.o : $(PRJ_ROOT_DIR)/XML/src/xmlparse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmlrole.o : $(PRJ_ROOT_DIR)/XML/src/xmlrole.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok.o : $(PRJ_ROOT_DIR)/XML/src/xmltok.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok_impl.o : $(PRJ_ROOT_DIR)/XML/src/xmltok_impl.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok_ns.o : $(PRJ_ROOT_DIR)/XML/src/xmltok_ns.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


libPocoLib/$(MODE_DIR)/Objects/PocoLib/main.o : $(PRJ_ROOT_DIR)/main.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_libPocoLib = libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ASCIIEncoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AbstractObserver.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ActiveDispatcher.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ArchiveStrategy.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Ascii.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AsyncChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AtomicCounter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base32Decoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base32Encoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base64Decoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base64Encoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/BinaryReader.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/BinaryWriter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Bugcheck.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ByteOrder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Channel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Checksum.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Clock.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Condition.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Configurable.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ConsoleChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/CountingStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTime.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeFormat.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeFormatter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeParser.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Debugger.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DeflatingStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DigestEngine.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DigestStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIterator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIteratorStrategy.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIterator_UNIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryWatcher.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Environment.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Environment_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Error.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ErrorHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/EventArgs.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Exception.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FIFOBufferStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FPEnvironment.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FPEnvironment_C99.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/File.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStreamFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStream_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/File_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Format.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Formatter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FormattingChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Glob.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Hash.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HashStatistic.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HexBinaryDecoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HexBinaryEncoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/InflatingStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin1Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin2Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin9Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LineEndingConverter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LocalDateTime.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogFile.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogFile_STD.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Logger.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LoggingFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LoggingRegistry.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MD4Engine.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MD5Engine.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Manifest.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MemoryPool.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MemoryStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Message.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent_Android.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent_UNIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex_Android.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex_UNIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NestedDiagnosticContext.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Notification.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NotificationCenter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NotificationQueue.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NullChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NullStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumberFormatter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumberParser.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumericString.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Path.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Path_UNIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PatternFormatter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Pipe.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl_DUMMY.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PriorityNotificationQueue.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Process.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Process_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PurgeStrategy.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock_Android.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Random.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RandomStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RefCountedObject.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RegularExpression.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RotateStrategy.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Runnable.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SHA1Engine.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory_DUMMY.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SignalHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SimpleFileChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SortedDirectoryIterator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SplitterChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Stopwatch.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamConverter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamCopier.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamTokenizer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/String.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StringTokenizer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SynchronizedObject.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SyslogChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Task.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TaskManager.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TaskNotification.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TeeStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TemporaryFile.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextBufferIterator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextConverter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextEncoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextIterator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadLocal.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadPool.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadTarget.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread_POSIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TimedNotificationQueue.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timespan.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timestamp.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone_UNIX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone_VX.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Token.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URI.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URIStreamFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URIStreamOpener.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF16Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF32Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF8Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF8String.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UUID.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UUIDGenerator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Unicode.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UnicodeConverter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Var.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/VarHolder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/VarIterator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Void.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1250Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1251Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1252Encoding.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/adler32.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/bignum-dtoa.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/bignum.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/cached-powers.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/compress.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/crc32.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/deflate.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/diy-fp.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/double-conversion.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/fast-dtoa.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/fixed-dtoa.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/infback.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inffast.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inflate.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inftrees.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_byte_order.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_chartables.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_compile.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_config.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_dfa_exec.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_exec.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_fullinfo.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_get.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_globals.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_jit_compile.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_maketables.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_newline.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_ord2utf8.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_refcount.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_string_utils.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_study.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_tables.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_ucd.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_valid_utf8.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_version.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_xclass.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/strtod.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/trees.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/zutil.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Array.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Handler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/JSONException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Object.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/ParseHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Parser.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/PrintHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Query.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Stringifier.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Template.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/TemplateCache.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/AbstractHTTPRequestHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DNS.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DatagramSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DatagramSocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DialogSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FTPClientSession.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FTPStreamFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FilePartSource.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTMLForm.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPAuthenticationParams.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPBasicCredentials.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPBufferAllocator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPChunkedStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPClientSession.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPCookie.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPCredentials.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPDigestCredentials.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPFixedLengthStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPHeaderStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPIOStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPMessage.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequest.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequestHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequestHandlerFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPResponse.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerConnection.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerConnectionFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerParams.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerRequest.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerRequestImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerResponse.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerResponseImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerSession.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSession.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSessionFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSessionInstantiator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPStreamFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HostEntry.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPClient.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPEventArgs.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPPacket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPPacketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPSocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPv4PacketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/IPAddress.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/IPAddressImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailMessage.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailRecipient.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MediaType.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MessageHeader.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MulticastSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MultipartReader.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MultipartWriter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPClient.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPEventArgs.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPPacket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NameValueCollection.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/Net.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NetException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NetworkInterface.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NullPartHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/OAuth10Credentials.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/OAuth20Credentials.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/POP3ClientSession.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartSource.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartStore.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/QuotedPrintableDecoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/QuotedPrintableEncoder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RawSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RawSocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RemoteSyslogChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RemoteSyslogListener.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SMTPChannel.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SMTPClientSession.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ServerSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ServerSocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/Socket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketAddress.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketAddressImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketNotification.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketNotifier.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketReactor.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketStream.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StreamSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StreamSocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StringPartSource.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerConnection.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerConnectionFactory.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerDispatcher.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerParams.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/WebSocket.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/WebSocketImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/AbstractConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Application.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ConfigurationMapper.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ConfigurationView.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/FilesystemConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/HelpFormatter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/IniFileConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/IntValidator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/JSONConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LayeredConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LoggingConfigurator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LoggingSubsystem.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/MapConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Option.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionCallback.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionProcessor.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionSet.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/PropertyFileConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/RegExpValidator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ServerApplication.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Subsystem.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/SystemConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Timer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/TimerTask.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Validator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/XMLConfiguration.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AbstractContainerNode.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AbstractNode.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Attr.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AttrMap.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Attributes.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AttributesImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/CDATASection.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/CharacterData.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ChildNodesList.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Comment.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ContentHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMBuilder.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMImplementation.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMObject.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMParser.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMSerializer.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMWriter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DTDHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DTDMap.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DeclHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DefaultHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Document.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentEvent.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentFragment.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentType.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Element.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ElementsByTagNameList.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Entity.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityReference.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityResolver.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityResolverImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ErrorHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Event.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventDispatcher.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventListener.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventTarget.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/InputSource.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/LexicalHandler.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Locator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/LocatorImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/MutationEvent.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Name.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamePool.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamedNodeMap.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamespaceStrategy.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamespaceSupport.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Node.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeAppender.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeFilter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeIterator.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeList.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Notation.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ParserEngine.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ProcessingInstruction.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/SAXException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/SAXParser.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Text.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/TreeWalker.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/WhitespaceFilter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLException.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLFilter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLFilterImpl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLReader.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLString.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLWriter.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmlparse.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmlrole.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok_impl.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok_ns.o \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/main.o

libPocoLib/$(MODE_DIR)/libPocoLib.a : $(OBJECTS_libPocoLib)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)arpentium crus "$@" $(OBJECTS_libPocoLib) $(ADDED_OBJECTS)

libPocoLib/$(MODE_DIR)/libPocoLib_compile_file : $(FILE) ;

_clean :: libPocoLib/$(MODE_DIR)/libPocoLib_clean

libPocoLib/$(MODE_DIR)/libPocoLib_clean : 
	$(TRACE_FLAG)if [ -d "libPocoLib" ]; then cd "libPocoLib"; rm -rf $(MODE_DIR); fi

DEP_FILES := libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ASCIIEncoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AbstractObserver.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ActiveDispatcher.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ArchiveStrategy.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Ascii.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AsyncChannel.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/AtomicCounter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base32Decoder.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base32Encoder.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base64Decoder.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Base64Encoder.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/BinaryReader.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/BinaryWriter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Bugcheck.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ByteOrder.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Channel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Checksum.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Clock.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Condition.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Configurable.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ConsoleChannel.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/CountingStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTime.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeFormat.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeFormatter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DateTimeParser.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Debugger.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DeflatingStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DigestEngine.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DigestStream.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIterator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIteratorStrategy.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryIterator_UNIX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/DirectoryWatcher.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Environment.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Environment_VX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Error.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ErrorHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/EventArgs.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event_POSIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Event_VX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Exception.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FIFOBufferStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FPEnvironment.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FPEnvironment_C99.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/File.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileChannel.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStreamFactory.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FileStream_POSIX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/File_VX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Format.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Formatter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/FormattingChannel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Glob.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Hash.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HashStatistic.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HexBinaryDecoder.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/HexBinaryEncoder.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/InflatingStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin1Encoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin2Encoding.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Latin9Encoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LineEndingConverter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LocalDateTime.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogFile.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogFile_STD.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LogStream.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Logger.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LoggingFactory.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/LoggingRegistry.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MD4Engine.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MD5Engine.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Manifest.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MemoryPool.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/MemoryStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Message.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex_POSIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Mutex_VX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent_Android.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedEvent_UNIX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex_Android.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NamedMutex_UNIX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NestedDiagnosticContext.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Notification.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NotificationCenter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NotificationQueue.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NullChannel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NullStream.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumberFormatter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumberParser.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/NumericString.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Path.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Path_UNIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PatternFormatter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Pipe.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl_DUMMY.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeImpl_POSIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PipeStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PriorityNotificationQueue.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Process.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Process_VX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/PurgeStrategy.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock_Android.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RWLock_VX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Random.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RandomStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RefCountedObject.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RegularExpression.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/RotateStrategy.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Runnable.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SHA1Engine.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore_POSIX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Semaphore_VX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory_DUMMY.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SharedMemory_POSIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SignalHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SimpleFileChannel.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SortedDirectoryIterator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SplitterChannel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Stopwatch.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamChannel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamConverter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamCopier.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StreamTokenizer.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/String.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/StringTokenizer.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SynchronizedObject.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/SyslogChannel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Task.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TaskManager.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TaskNotification.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TeeStream.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TemporaryFile.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextBufferIterator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextConverter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextEncoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TextIterator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadLocal.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadPool.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/ThreadTarget.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread_POSIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Thread_VX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/TimedNotificationQueue.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timer.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timespan.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timestamp.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone_UNIX.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Timezone_VX.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Token.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URI.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URIStreamFactory.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/URIStreamOpener.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF16Encoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF32Encoding.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF8Encoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UTF8String.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UUID.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UUIDGenerator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Unicode.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/UnicodeConverter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Var.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/VarHolder.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/VarIterator.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Void.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1250Encoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1251Encoding.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/Windows1252Encoding.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/adler32.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/bignum-dtoa.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/bignum.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/cached-powers.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/compress.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/crc32.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/deflate.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/diy-fp.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/double-conversion.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/fast-dtoa.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/fixed-dtoa.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/infback.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inffast.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inflate.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/inftrees.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_byte_order.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_chartables.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_compile.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_config.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_dfa_exec.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_exec.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_fullinfo.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_get.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_globals.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_jit_compile.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_maketables.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_newline.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_ord2utf8.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_refcount.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_string_utils.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_study.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_tables.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_ucd.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_valid_utf8.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_version.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/pcre_xclass.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/strtod.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/trees.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Foundation/src/zutil.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Array.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Handler.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/JSONException.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Object.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/ParseHandler.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Parser.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/PrintHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Query.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Stringifier.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/Template.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/JSON/src/TemplateCache.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/AbstractHTTPRequestHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DNS.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DatagramSocket.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DatagramSocketImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/DialogSocket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FTPClientSession.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FTPStreamFactory.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/FilePartSource.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTMLForm.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPAuthenticationParams.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPBasicCredentials.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPBufferAllocator.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPChunkedStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPClientSession.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPCookie.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPCredentials.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPDigestCredentials.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPFixedLengthStream.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPHeaderStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPIOStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPMessage.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequest.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequestHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPRequestHandlerFactory.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPResponse.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServer.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerConnection.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerConnectionFactory.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerParams.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerRequest.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerRequestImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerResponse.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerResponseImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPServerSession.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSession.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSessionFactory.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPSessionInstantiator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HTTPStreamFactory.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/HostEntry.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPClient.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPEventArgs.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPPacket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPPacketImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPSocket.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPSocketImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ICMPv4PacketImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/IPAddress.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/IPAddressImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailMessage.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailRecipient.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MailStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MediaType.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MessageHeader.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MulticastSocket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MultipartReader.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/MultipartWriter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPClient.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPEventArgs.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NTPPacket.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NameValueCollection.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/Net.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NetException.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NetworkInterface.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/NullPartHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/OAuth10Credentials.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/OAuth20Credentials.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/POP3ClientSession.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartHandler.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartSource.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/PartStore.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/QuotedPrintableDecoder.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/QuotedPrintableEncoder.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RawSocket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RawSocketImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RemoteSyslogChannel.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/RemoteSyslogListener.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SMTPChannel.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SMTPClientSession.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ServerSocket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/ServerSocketImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/Socket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketAddress.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketAddressImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketNotification.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketNotifier.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketReactor.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/SocketStream.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StreamSocket.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StreamSocketImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/StringPartSource.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServer.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerConnection.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerConnectionFactory.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerDispatcher.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/TCPServerParams.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/WebSocket.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Net/src/WebSocketImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/AbstractConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Application.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ConfigurationMapper.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ConfigurationView.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/FilesystemConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/HelpFormatter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/IniFileConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/IntValidator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/JSONConfiguration.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LayeredConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LoggingConfigurator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/LoggingSubsystem.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/MapConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Option.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionCallback.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionException.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionProcessor.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/OptionSet.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/PropertyFileConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/RegExpValidator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/ServerApplication.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Subsystem.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/SystemConfiguration.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Timer.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/TimerTask.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/Validator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/Util/src/XMLConfiguration.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AbstractContainerNode.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AbstractNode.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Attr.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AttrMap.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Attributes.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/AttributesImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/CDATASection.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/CharacterData.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ChildNodesList.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Comment.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ContentHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMBuilder.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMException.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMImplementation.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMObject.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMParser.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMSerializer.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DOMWriter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DTDHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DTDMap.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DeclHandler.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DefaultHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Document.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentEvent.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentFragment.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/DocumentType.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Element.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ElementsByTagNameList.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Entity.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityReference.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityResolver.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EntityResolverImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ErrorHandler.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Event.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventDispatcher.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventException.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventListener.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/EventTarget.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/InputSource.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/LexicalHandler.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Locator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/LocatorImpl.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/MutationEvent.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Name.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamePool.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamedNodeMap.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamespaceStrategy.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NamespaceSupport.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Node.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeAppender.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeFilter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeIterator.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/NodeList.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Notation.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ParserEngine.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/ProcessingInstruction.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/SAXException.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/SAXParser.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/Text.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/TreeWalker.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/WhitespaceFilter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLException.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLFilter.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLFilterImpl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLReader.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLString.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/XMLWriter.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmlparse.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmlrole.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok_impl.d libPocoLib/$(MODE_DIR)/Objects/PocoLib/XML/src/xmltok_ns.d \
	 libPocoLib/$(MODE_DIR)/Objects/PocoLib/main.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
