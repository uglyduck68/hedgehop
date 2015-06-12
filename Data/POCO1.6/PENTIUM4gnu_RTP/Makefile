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
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/POCO1.6



#Global Build Macros
PROJECT_TYPE = SL
DEFINES = -DPOCO_VXWORKS -DVXWORKS_VERSION_MAJOR=6 -DVXWORKS_VERSION_MINOR=8
DO_STRIP = 0
SHAREDLIB_VERSION = 
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

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/h/sys -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(WIND_HOME)/workspace/POCO1.6/Foundation/include -I$(WIND_HOME)/workspace/POCO1.6/JSON/include -I$(WIND_HOME)/workspace/POCO1.6/Net/include -I$(WIND_HOME)/workspace/POCO1.6/Util/include -I$(WIND_HOME)/workspace/POCO1.6/XML/include 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Shared-Library-Linker = 
DEBUGFLAGS_Static-Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2   
DEBUGFLAGS_C++-Compiler = -O2   
DEBUGFLAGS_Shared-Library-Linker = 
DEBUGFLAGS_Static-Librarian = 
DEBUGFLAGS_Assembler = -O2   
endif


#Project Targets
PROJECT_TARGETS = POCO1.6/$(MODE_DIR)/POCO1.6.so


#Rules

# POCO1.6
ifeq ($(DEBUG_MODE),1)
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_Shared-Library-Linker = 
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_Static-Librarian = 
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2   
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2   
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_Shared-Library-Linker = 
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_Static-Librarian = 
POCO1.6/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2   
endif
POCO1.6/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/h/sys -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(WIND_HOME)/workspace/POCO1.6/Foundation/include -I$(WIND_HOME)/workspace/POCO1.6/JSON/include -I$(WIND_HOME)/workspace/POCO1.6/Net/include -I$(WIND_HOME)/workspace/POCO1.6/Util/include -I$(WIND_HOME)/workspace/POCO1.6/XML/include 
POCO1.6/$(MODE_DIR)/% : IDE_LIBRARIES = 
POCO1.6/$(MODE_DIR)/% : PROJECT_TYPE = SL
POCO1.6/$(MODE_DIR)/% : DEFINES = -DPOCO_VXWORKS -DVXWORKS_VERSION_MAJOR=6 -DVXWORKS_VERSION_MINOR=8
POCO1.6/$(MODE_DIR)/% : DO_STRIP = 0
POCO1.6/$(MODE_DIR)/% : SHAREDLIB_VERSION = 
POCO1.6/$(MODE_DIR)/% : EXPAND_DBG = 0
POCO1.6/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
POCO1.6/$(MODE_DIR)/% : CPU = PENTIUM4
POCO1.6/$(MODE_DIR)/% : TOOL_FAMILY = gnu
POCO1.6/$(MODE_DIR)/% : TOOL = gnu
POCO1.6/$(MODE_DIR)/% : TOOL_PATH = 
POCO1.6/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4
POCO1.6/$(MODE_DIR)/% : LIBPATH = 
POCO1.6/$(MODE_DIR)/% : LIBS = -lstdc++
POCO1.6/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
POCO1.6/$(MODE_DIR)/% : OBJ_DIR := POCO1.6/$(MODE_DIR)

POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ASCIIEncoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/ASCIIEncoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AbstractObserver.sho : $(PRJ_ROOT_DIR)/Foundation/src/AbstractObserver.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ActiveDispatcher.sho : $(PRJ_ROOT_DIR)/Foundation/src/ActiveDispatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ArchiveStrategy.sho : $(PRJ_ROOT_DIR)/Foundation/src/ArchiveStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Ascii.sho : $(PRJ_ROOT_DIR)/Foundation/src/Ascii.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AsyncChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/AsyncChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AtomicCounter.sho : $(PRJ_ROOT_DIR)/Foundation/src/AtomicCounter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base32Decoder.sho : $(PRJ_ROOT_DIR)/Foundation/src/Base32Decoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base32Encoder.sho : $(PRJ_ROOT_DIR)/Foundation/src/Base32Encoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base64Decoder.sho : $(PRJ_ROOT_DIR)/Foundation/src/Base64Decoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base64Encoder.sho : $(PRJ_ROOT_DIR)/Foundation/src/Base64Encoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/BinaryReader.sho : $(PRJ_ROOT_DIR)/Foundation/src/BinaryReader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/BinaryWriter.sho : $(PRJ_ROOT_DIR)/Foundation/src/BinaryWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Bugcheck.sho : $(PRJ_ROOT_DIR)/Foundation/src/Bugcheck.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ByteOrder.sho : $(PRJ_ROOT_DIR)/Foundation/src/ByteOrder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Channel.sho : $(PRJ_ROOT_DIR)/Foundation/src/Channel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Checksum.sho : $(PRJ_ROOT_DIR)/Foundation/src/Checksum.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Clock.sho : $(PRJ_ROOT_DIR)/Foundation/src/Clock.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Condition.sho : $(PRJ_ROOT_DIR)/Foundation/src/Condition.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Configurable.sho : $(PRJ_ROOT_DIR)/Foundation/src/Configurable.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ConsoleChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/ConsoleChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/CountingStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/CountingStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTime.sho : $(PRJ_ROOT_DIR)/Foundation/src/DateTime.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeFormat.sho : $(PRJ_ROOT_DIR)/Foundation/src/DateTimeFormat.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeFormatter.sho : $(PRJ_ROOT_DIR)/Foundation/src/DateTimeFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeParser.sho : $(PRJ_ROOT_DIR)/Foundation/src/DateTimeParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Debugger.sho : $(PRJ_ROOT_DIR)/Foundation/src/Debugger.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DeflatingStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/DeflatingStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DigestEngine.sho : $(PRJ_ROOT_DIR)/Foundation/src/DigestEngine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DigestStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/DigestStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIterator.sho : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIteratorStrategy.sho : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryIteratorStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIterator_UNIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryIterator_UNIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryWatcher.sho : $(PRJ_ROOT_DIR)/Foundation/src/DirectoryWatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Environment.sho : $(PRJ_ROOT_DIR)/Foundation/src/Environment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Environment_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Environment_VX.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Error.sho : $(PRJ_ROOT_DIR)/Foundation/src/Error.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ErrorHandler.sho : $(PRJ_ROOT_DIR)/Foundation/src/ErrorHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event.sho : $(PRJ_ROOT_DIR)/Foundation/src/Event.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/EventArgs.sho : $(PRJ_ROOT_DIR)/Foundation/src/EventArgs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event_POSIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Event_POSIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Event_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Exception.sho : $(PRJ_ROOT_DIR)/Foundation/src/Exception.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FIFOBufferStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/FIFOBufferStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FPEnvironment.sho : $(PRJ_ROOT_DIR)/Foundation/src/FPEnvironment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FPEnvironment_C99.sho : $(PRJ_ROOT_DIR)/Foundation/src/FPEnvironment_C99.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/File.sho : $(PRJ_ROOT_DIR)/Foundation/src/File.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/FileChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/FileStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStreamFactory.sho : $(PRJ_ROOT_DIR)/Foundation/src/FileStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStream_POSIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/FileStream_POSIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/File_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/File_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Format.sho : $(PRJ_ROOT_DIR)/Foundation/src/Format.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Formatter.sho : $(PRJ_ROOT_DIR)/Foundation/src/Formatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FormattingChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/FormattingChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Glob.sho : $(PRJ_ROOT_DIR)/Foundation/src/Glob.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Hash.sho : $(PRJ_ROOT_DIR)/Foundation/src/Hash.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HashStatistic.sho : $(PRJ_ROOT_DIR)/Foundation/src/HashStatistic.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HexBinaryDecoder.sho : $(PRJ_ROOT_DIR)/Foundation/src/HexBinaryDecoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HexBinaryEncoder.sho : $(PRJ_ROOT_DIR)/Foundation/src/HexBinaryEncoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/InflatingStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/InflatingStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin1Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/Latin1Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin2Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/Latin2Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin9Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/Latin9Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LineEndingConverter.sho : $(PRJ_ROOT_DIR)/Foundation/src/LineEndingConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LocalDateTime.sho : $(PRJ_ROOT_DIR)/Foundation/src/LocalDateTime.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogFile.sho : $(PRJ_ROOT_DIR)/Foundation/src/LogFile.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogFile_STD.sho : $(PRJ_ROOT_DIR)/Foundation/src/LogFile_STD.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/LogStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Logger.sho : $(PRJ_ROOT_DIR)/Foundation/src/Logger.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LoggingFactory.sho : $(PRJ_ROOT_DIR)/Foundation/src/LoggingFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LoggingRegistry.sho : $(PRJ_ROOT_DIR)/Foundation/src/LoggingRegistry.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MD4Engine.sho : $(PRJ_ROOT_DIR)/Foundation/src/MD4Engine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MD5Engine.sho : $(PRJ_ROOT_DIR)/Foundation/src/MD5Engine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Manifest.sho : $(PRJ_ROOT_DIR)/Foundation/src/Manifest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MemoryPool.sho : $(PRJ_ROOT_DIR)/Foundation/src/MemoryPool.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MemoryStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/MemoryStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Message.sho : $(PRJ_ROOT_DIR)/Foundation/src/Message.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex.sho : $(PRJ_ROOT_DIR)/Foundation/src/Mutex.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex_POSIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Mutex_POSIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Mutex_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent.sho : $(PRJ_ROOT_DIR)/Foundation/src/NamedEvent.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent_Android.sho : $(PRJ_ROOT_DIR)/Foundation/src/NamedEvent_Android.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent_UNIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/NamedEvent_UNIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex.sho : $(PRJ_ROOT_DIR)/Foundation/src/NamedMutex.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex_Android.sho : $(PRJ_ROOT_DIR)/Foundation/src/NamedMutex_Android.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex_UNIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/NamedMutex_UNIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NestedDiagnosticContext.sho : $(PRJ_ROOT_DIR)/Foundation/src/NestedDiagnosticContext.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Notification.sho : $(PRJ_ROOT_DIR)/Foundation/src/Notification.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NotificationCenter.sho : $(PRJ_ROOT_DIR)/Foundation/src/NotificationCenter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NotificationQueue.sho : $(PRJ_ROOT_DIR)/Foundation/src/NotificationQueue.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NullChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/NullChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NullStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/NullStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumberFormatter.sho : $(PRJ_ROOT_DIR)/Foundation/src/NumberFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumberParser.sho : $(PRJ_ROOT_DIR)/Foundation/src/NumberParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumericString.sho : $(PRJ_ROOT_DIR)/Foundation/src/NumericString.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Path.sho : $(PRJ_ROOT_DIR)/Foundation/src/Path.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Path_UNIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Path_UNIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PatternFormatter.sho : $(PRJ_ROOT_DIR)/Foundation/src/PatternFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Pipe.sho : $(PRJ_ROOT_DIR)/Foundation/src/Pipe.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl.sho : $(PRJ_ROOT_DIR)/Foundation/src/PipeImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl_DUMMY.sho : $(PRJ_ROOT_DIR)/Foundation/src/PipeImpl_DUMMY.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl_POSIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/PipeImpl_POSIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/PipeStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PriorityNotificationQueue.sho : $(PRJ_ROOT_DIR)/Foundation/src/PriorityNotificationQueue.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Process.sho : $(PRJ_ROOT_DIR)/Foundation/src/Process.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Process_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Process_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PurgeStrategy.sho : $(PRJ_ROOT_DIR)/Foundation/src/PurgeStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock.sho : $(PRJ_ROOT_DIR)/Foundation/src/RWLock.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock_Android.sho : $(PRJ_ROOT_DIR)/Foundation/src/RWLock_Android.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/RWLock_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Random.sho : $(PRJ_ROOT_DIR)/Foundation/src/Random.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RandomStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/RandomStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RefCountedObject.sho : $(PRJ_ROOT_DIR)/Foundation/src/RefCountedObject.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RegularExpression.sho : $(PRJ_ROOT_DIR)/Foundation/src/RegularExpression.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RotateStrategy.sho : $(PRJ_ROOT_DIR)/Foundation/src/RotateStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Runnable.sho : $(PRJ_ROOT_DIR)/Foundation/src/Runnable.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SHA1Engine.sho : $(PRJ_ROOT_DIR)/Foundation/src/SHA1Engine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore.sho : $(PRJ_ROOT_DIR)/Foundation/src/Semaphore.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore_POSIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Semaphore_POSIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Semaphore_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory.sho : $(PRJ_ROOT_DIR)/Foundation/src/SharedMemory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory_DUMMY.sho : $(PRJ_ROOT_DIR)/Foundation/src/SharedMemory_DUMMY.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory_POSIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/SharedMemory_POSIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SignalHandler.sho : $(PRJ_ROOT_DIR)/Foundation/src/SignalHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SimpleFileChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/SimpleFileChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SortedDirectoryIterator.sho : $(PRJ_ROOT_DIR)/Foundation/src/SortedDirectoryIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SplitterChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/SplitterChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Stopwatch.sho : $(PRJ_ROOT_DIR)/Foundation/src/Stopwatch.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/StreamChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamConverter.sho : $(PRJ_ROOT_DIR)/Foundation/src/StreamConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamCopier.sho : $(PRJ_ROOT_DIR)/Foundation/src/StreamCopier.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamTokenizer.sho : $(PRJ_ROOT_DIR)/Foundation/src/StreamTokenizer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/String.sho : $(PRJ_ROOT_DIR)/Foundation/src/String.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StringTokenizer.sho : $(PRJ_ROOT_DIR)/Foundation/src/StringTokenizer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SynchronizedObject.sho : $(PRJ_ROOT_DIR)/Foundation/src/SynchronizedObject.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SyslogChannel.sho : $(PRJ_ROOT_DIR)/Foundation/src/SyslogChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Task.sho : $(PRJ_ROOT_DIR)/Foundation/src/Task.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TaskManager.sho : $(PRJ_ROOT_DIR)/Foundation/src/TaskManager.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TaskNotification.sho : $(PRJ_ROOT_DIR)/Foundation/src/TaskNotification.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TeeStream.sho : $(PRJ_ROOT_DIR)/Foundation/src/TeeStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TemporaryFile.sho : $(PRJ_ROOT_DIR)/Foundation/src/TemporaryFile.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextBufferIterator.sho : $(PRJ_ROOT_DIR)/Foundation/src/TextBufferIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextConverter.sho : $(PRJ_ROOT_DIR)/Foundation/src/TextConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextEncoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/TextEncoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextIterator.sho : $(PRJ_ROOT_DIR)/Foundation/src/TextIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Thread.sho : $(PRJ_ROOT_DIR)/Foundation/src/Thread.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadLocal.sho : $(PRJ_ROOT_DIR)/Foundation/src/ThreadLocal.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadPool.sho : $(PRJ_ROOT_DIR)/Foundation/src/ThreadPool.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadTarget.sho : $(PRJ_ROOT_DIR)/Foundation/src/ThreadTarget.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Thread_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Thread_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TimedNotificationQueue.sho : $(PRJ_ROOT_DIR)/Foundation/src/TimedNotificationQueue.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timer.sho : $(PRJ_ROOT_DIR)/Foundation/src/Timer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timespan.sho : $(PRJ_ROOT_DIR)/Foundation/src/Timespan.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timestamp.sho : $(PRJ_ROOT_DIR)/Foundation/src/Timestamp.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone.sho : $(PRJ_ROOT_DIR)/Foundation/src/Timezone.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone_UNIX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Timezone_UNIX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone_VX.sho : $(PRJ_ROOT_DIR)/Foundation/src/Timezone_VX.cpp
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Token.sho : $(PRJ_ROOT_DIR)/Foundation/src/Token.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URI.sho : $(PRJ_ROOT_DIR)/Foundation/src/URI.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URIStreamFactory.sho : $(PRJ_ROOT_DIR)/Foundation/src/URIStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URIStreamOpener.sho : $(PRJ_ROOT_DIR)/Foundation/src/URIStreamOpener.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF16Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/UTF16Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF32Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/UTF32Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF8Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/UTF8Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF8String.sho : $(PRJ_ROOT_DIR)/Foundation/src/UTF8String.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UUID.sho : $(PRJ_ROOT_DIR)/Foundation/src/UUID.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UUIDGenerator.sho : $(PRJ_ROOT_DIR)/Foundation/src/UUIDGenerator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Unicode.sho : $(PRJ_ROOT_DIR)/Foundation/src/Unicode.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UnicodeConverter.sho : $(PRJ_ROOT_DIR)/Foundation/src/UnicodeConverter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Var.sho : $(PRJ_ROOT_DIR)/Foundation/src/Var.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/VarHolder.sho : $(PRJ_ROOT_DIR)/Foundation/src/VarHolder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/VarIterator.sho : $(PRJ_ROOT_DIR)/Foundation/src/VarIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Void.sho : $(PRJ_ROOT_DIR)/Foundation/src/Void.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1250Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/Windows1250Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1251Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/Windows1251Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1252Encoding.sho : $(PRJ_ROOT_DIR)/Foundation/src/Windows1252Encoding.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/adler32.sho : $(PRJ_ROOT_DIR)/Foundation/src/adler32.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/bignum-dtoa.sho : $(PRJ_ROOT_DIR)/Foundation/src/bignum-dtoa.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/bignum.sho : $(PRJ_ROOT_DIR)/Foundation/src/bignum.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/cached-powers.sho : $(PRJ_ROOT_DIR)/Foundation/src/cached-powers.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/compress.sho : $(PRJ_ROOT_DIR)/Foundation/src/compress.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/crc32.sho : $(PRJ_ROOT_DIR)/Foundation/src/crc32.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/deflate.sho : $(PRJ_ROOT_DIR)/Foundation/src/deflate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/diy-fp.sho : $(PRJ_ROOT_DIR)/Foundation/src/diy-fp.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/double-conversion.sho : $(PRJ_ROOT_DIR)/Foundation/src/double-conversion.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/fast-dtoa.sho : $(PRJ_ROOT_DIR)/Foundation/src/fast-dtoa.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/fixed-dtoa.sho : $(PRJ_ROOT_DIR)/Foundation/src/fixed-dtoa.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/infback.sho : $(PRJ_ROOT_DIR)/Foundation/src/infback.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inffast.sho : $(PRJ_ROOT_DIR)/Foundation/src/inffast.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inflate.sho : $(PRJ_ROOT_DIR)/Foundation/src/inflate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inftrees.sho : $(PRJ_ROOT_DIR)/Foundation/src/inftrees.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_byte_order.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_byte_order.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_chartables.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_chartables.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_compile.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_compile.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_config.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_config.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_dfa_exec.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_dfa_exec.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_exec.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_exec.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_fullinfo.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_fullinfo.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_get.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_get.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_globals.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_globals.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_jit_compile.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_jit_compile.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_maketables.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_maketables.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_newline.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_newline.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_ord2utf8.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_ord2utf8.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_refcount.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_refcount.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_string_utils.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_string_utils.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_study.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_study.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_tables.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_tables.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_ucd.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_ucd.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_valid_utf8.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_valid_utf8.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_version.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_version.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_xclass.sho : $(PRJ_ROOT_DIR)/Foundation/src/pcre_xclass.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


#POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/strtod.sho : $(PRJ_ROOT_DIR)/Foundation/src/strtod.cc
#	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/trees.sho : $(PRJ_ROOT_DIR)/Foundation/src/trees.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/zutil.sho : $(PRJ_ROOT_DIR)/Foundation/src/zutil.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Array.sho : $(PRJ_ROOT_DIR)/JSON/src/Array.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Handler.sho : $(PRJ_ROOT_DIR)/JSON/src/Handler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/JSONException.sho : $(PRJ_ROOT_DIR)/JSON/src/JSONException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Object.sho : $(PRJ_ROOT_DIR)/JSON/src/Object.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/ParseHandler.sho : $(PRJ_ROOT_DIR)/JSON/src/ParseHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Parser.sho : $(PRJ_ROOT_DIR)/JSON/src/Parser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/PrintHandler.sho : $(PRJ_ROOT_DIR)/JSON/src/PrintHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Query.sho : $(PRJ_ROOT_DIR)/JSON/src/Query.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Stringifier.sho : $(PRJ_ROOT_DIR)/JSON/src/Stringifier.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Template.sho : $(PRJ_ROOT_DIR)/JSON/src/Template.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/TemplateCache.sho : $(PRJ_ROOT_DIR)/JSON/src/TemplateCache.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/AbstractHTTPRequestHandler.sho : $(PRJ_ROOT_DIR)/Net/src/AbstractHTTPRequestHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DNS.sho : $(PRJ_ROOT_DIR)/Net/src/DNS.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DatagramSocket.sho : $(PRJ_ROOT_DIR)/Net/src/DatagramSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DatagramSocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/DatagramSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DialogSocket.sho : $(PRJ_ROOT_DIR)/Net/src/DialogSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FTPClientSession.sho : $(PRJ_ROOT_DIR)/Net/src/FTPClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FTPStreamFactory.sho : $(PRJ_ROOT_DIR)/Net/src/FTPStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FilePartSource.sho : $(PRJ_ROOT_DIR)/Net/src/FilePartSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTMLForm.sho : $(PRJ_ROOT_DIR)/Net/src/HTMLForm.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPAuthenticationParams.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPAuthenticationParams.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPBasicCredentials.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPBasicCredentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPBufferAllocator.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPBufferAllocator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPChunkedStream.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPChunkedStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPClientSession.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPCookie.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPCookie.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPCredentials.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPCredentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPDigestCredentials.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPDigestCredentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPFixedLengthStream.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPFixedLengthStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPHeaderStream.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPHeaderStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPIOStream.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPIOStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPMessage.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPMessage.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequest.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPRequest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequestHandler.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPRequestHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequestHandlerFactory.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPRequestHandlerFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPResponse.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPResponse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServer.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerConnection.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerConnection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerConnectionFactory.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerConnectionFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerParams.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerParams.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerRequest.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerRequest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerRequestImpl.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerRequestImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerResponse.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerResponse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerResponseImpl.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerResponseImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerSession.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPServerSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSession.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSessionFactory.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPSessionFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSessionInstantiator.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPSessionInstantiator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPStream.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPStreamFactory.sho : $(PRJ_ROOT_DIR)/Net/src/HTTPStreamFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HostEntry.sho : $(PRJ_ROOT_DIR)/Net/src/HostEntry.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPClient.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPClient.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPEventArgs.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPEventArgs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPPacket.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPPacket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPPacketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPPacketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPSocket.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPSocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPv4PacketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/ICMPv4PacketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/IPAddress.sho : $(PRJ_ROOT_DIR)/Net/src/IPAddress.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/IPAddressImpl.sho : $(PRJ_ROOT_DIR)/Net/src/IPAddressImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailMessage.sho : $(PRJ_ROOT_DIR)/Net/src/MailMessage.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailRecipient.sho : $(PRJ_ROOT_DIR)/Net/src/MailRecipient.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailStream.sho : $(PRJ_ROOT_DIR)/Net/src/MailStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MediaType.sho : $(PRJ_ROOT_DIR)/Net/src/MediaType.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MessageHeader.sho : $(PRJ_ROOT_DIR)/Net/src/MessageHeader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MulticastSocket.sho : $(PRJ_ROOT_DIR)/Net/src/MulticastSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MultipartReader.sho : $(PRJ_ROOT_DIR)/Net/src/MultipartReader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MultipartWriter.sho : $(PRJ_ROOT_DIR)/Net/src/MultipartWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPClient.sho : $(PRJ_ROOT_DIR)/Net/src/NTPClient.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPEventArgs.sho : $(PRJ_ROOT_DIR)/Net/src/NTPEventArgs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPPacket.sho : $(PRJ_ROOT_DIR)/Net/src/NTPPacket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NameValueCollection.sho : $(PRJ_ROOT_DIR)/Net/src/NameValueCollection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/Net.sho : $(PRJ_ROOT_DIR)/Net/src/Net.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NetException.sho : $(PRJ_ROOT_DIR)/Net/src/NetException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NetworkInterface.sho : $(PRJ_ROOT_DIR)/Net/src/NetworkInterface.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NullPartHandler.sho : $(PRJ_ROOT_DIR)/Net/src/NullPartHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/OAuth10Credentials.sho : $(PRJ_ROOT_DIR)/Net/src/OAuth10Credentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/OAuth20Credentials.sho : $(PRJ_ROOT_DIR)/Net/src/OAuth20Credentials.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/POP3ClientSession.sho : $(PRJ_ROOT_DIR)/Net/src/POP3ClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartHandler.sho : $(PRJ_ROOT_DIR)/Net/src/PartHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartSource.sho : $(PRJ_ROOT_DIR)/Net/src/PartSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartStore.sho : $(PRJ_ROOT_DIR)/Net/src/PartStore.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/QuotedPrintableDecoder.sho : $(PRJ_ROOT_DIR)/Net/src/QuotedPrintableDecoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/QuotedPrintableEncoder.sho : $(PRJ_ROOT_DIR)/Net/src/QuotedPrintableEncoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RawSocket.sho : $(PRJ_ROOT_DIR)/Net/src/RawSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RawSocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/RawSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RemoteSyslogChannel.sho : $(PRJ_ROOT_DIR)/Net/src/RemoteSyslogChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RemoteSyslogListener.sho : $(PRJ_ROOT_DIR)/Net/src/RemoteSyslogListener.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SMTPChannel.sho : $(PRJ_ROOT_DIR)/Net/src/SMTPChannel.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SMTPClientSession.sho : $(PRJ_ROOT_DIR)/Net/src/SMTPClientSession.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ServerSocket.sho : $(PRJ_ROOT_DIR)/Net/src/ServerSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ServerSocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/ServerSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/Socket.sho : $(PRJ_ROOT_DIR)/Net/src/Socket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketAddress.sho : $(PRJ_ROOT_DIR)/Net/src/SocketAddress.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketAddressImpl.sho : $(PRJ_ROOT_DIR)/Net/src/SocketAddressImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/SocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketNotification.sho : $(PRJ_ROOT_DIR)/Net/src/SocketNotification.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketNotifier.sho : $(PRJ_ROOT_DIR)/Net/src/SocketNotifier.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketReactor.sho : $(PRJ_ROOT_DIR)/Net/src/SocketReactor.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketStream.sho : $(PRJ_ROOT_DIR)/Net/src/SocketStream.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StreamSocket.sho : $(PRJ_ROOT_DIR)/Net/src/StreamSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StreamSocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/StreamSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StringPartSource.sho : $(PRJ_ROOT_DIR)/Net/src/StringPartSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServer.sho : $(PRJ_ROOT_DIR)/Net/src/TCPServer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerConnection.sho : $(PRJ_ROOT_DIR)/Net/src/TCPServerConnection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerConnectionFactory.sho : $(PRJ_ROOT_DIR)/Net/src/TCPServerConnectionFactory.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerDispatcher.sho : $(PRJ_ROOT_DIR)/Net/src/TCPServerDispatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerParams.sho : $(PRJ_ROOT_DIR)/Net/src/TCPServerParams.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/WebSocket.sho : $(PRJ_ROOT_DIR)/Net/src/WebSocket.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/WebSocketImpl.sho : $(PRJ_ROOT_DIR)/Net/src/WebSocketImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/AbstractConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/AbstractConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Application.sho : $(PRJ_ROOT_DIR)/Util/src/Application.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ConfigurationMapper.sho : $(PRJ_ROOT_DIR)/Util/src/ConfigurationMapper.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ConfigurationView.sho : $(PRJ_ROOT_DIR)/Util/src/ConfigurationView.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/FilesystemConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/FilesystemConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/HelpFormatter.sho : $(PRJ_ROOT_DIR)/Util/src/HelpFormatter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/IniFileConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/IniFileConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/IntValidator.sho : $(PRJ_ROOT_DIR)/Util/src/IntValidator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/JSONConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/JSONConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LayeredConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/LayeredConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LoggingConfigurator.sho : $(PRJ_ROOT_DIR)/Util/src/LoggingConfigurator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LoggingSubsystem.sho : $(PRJ_ROOT_DIR)/Util/src/LoggingSubsystem.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/MapConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/MapConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Option.sho : $(PRJ_ROOT_DIR)/Util/src/Option.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionCallback.sho : $(PRJ_ROOT_DIR)/Util/src/OptionCallback.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionException.sho : $(PRJ_ROOT_DIR)/Util/src/OptionException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionProcessor.sho : $(PRJ_ROOT_DIR)/Util/src/OptionProcessor.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionSet.sho : $(PRJ_ROOT_DIR)/Util/src/OptionSet.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/PropertyFileConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/PropertyFileConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/RegExpValidator.sho : $(PRJ_ROOT_DIR)/Util/src/RegExpValidator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ServerApplication.sho : $(PRJ_ROOT_DIR)/Util/src/ServerApplication.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Subsystem.sho : $(PRJ_ROOT_DIR)/Util/src/Subsystem.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/SystemConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/SystemConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Timer.sho : $(PRJ_ROOT_DIR)/Util/src/Timer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/TimerTask.sho : $(PRJ_ROOT_DIR)/Util/src/TimerTask.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Validator.sho : $(PRJ_ROOT_DIR)/Util/src/Validator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/XMLConfiguration.sho : $(PRJ_ROOT_DIR)/Util/src/XMLConfiguration.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AbstractContainerNode.sho : $(PRJ_ROOT_DIR)/XML/src/AbstractContainerNode.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AbstractNode.sho : $(PRJ_ROOT_DIR)/XML/src/AbstractNode.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Attr.sho : $(PRJ_ROOT_DIR)/XML/src/Attr.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AttrMap.sho : $(PRJ_ROOT_DIR)/XML/src/AttrMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Attributes.sho : $(PRJ_ROOT_DIR)/XML/src/Attributes.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AttributesImpl.sho : $(PRJ_ROOT_DIR)/XML/src/AttributesImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/CDATASection.sho : $(PRJ_ROOT_DIR)/XML/src/CDATASection.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/CharacterData.sho : $(PRJ_ROOT_DIR)/XML/src/CharacterData.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ChildNodesList.sho : $(PRJ_ROOT_DIR)/XML/src/ChildNodesList.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Comment.sho : $(PRJ_ROOT_DIR)/XML/src/Comment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ContentHandler.sho : $(PRJ_ROOT_DIR)/XML/src/ContentHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMBuilder.sho : $(PRJ_ROOT_DIR)/XML/src/DOMBuilder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMException.sho : $(PRJ_ROOT_DIR)/XML/src/DOMException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMImplementation.sho : $(PRJ_ROOT_DIR)/XML/src/DOMImplementation.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMObject.sho : $(PRJ_ROOT_DIR)/XML/src/DOMObject.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMParser.sho : $(PRJ_ROOT_DIR)/XML/src/DOMParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMSerializer.sho : $(PRJ_ROOT_DIR)/XML/src/DOMSerializer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMWriter.sho : $(PRJ_ROOT_DIR)/XML/src/DOMWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DTDHandler.sho : $(PRJ_ROOT_DIR)/XML/src/DTDHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DTDMap.sho : $(PRJ_ROOT_DIR)/XML/src/DTDMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DeclHandler.sho : $(PRJ_ROOT_DIR)/XML/src/DeclHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DefaultHandler.sho : $(PRJ_ROOT_DIR)/XML/src/DefaultHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Document.sho : $(PRJ_ROOT_DIR)/XML/src/Document.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentEvent.sho : $(PRJ_ROOT_DIR)/XML/src/DocumentEvent.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentFragment.sho : $(PRJ_ROOT_DIR)/XML/src/DocumentFragment.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentType.sho : $(PRJ_ROOT_DIR)/XML/src/DocumentType.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Element.sho : $(PRJ_ROOT_DIR)/XML/src/Element.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ElementsByTagNameList.sho : $(PRJ_ROOT_DIR)/XML/src/ElementsByTagNameList.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Entity.sho : $(PRJ_ROOT_DIR)/XML/src/Entity.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityReference.sho : $(PRJ_ROOT_DIR)/XML/src/EntityReference.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityResolver.sho : $(PRJ_ROOT_DIR)/XML/src/EntityResolver.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityResolverImpl.sho : $(PRJ_ROOT_DIR)/XML/src/EntityResolverImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ErrorHandler.sho : $(PRJ_ROOT_DIR)/XML/src/ErrorHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Event.sho : $(PRJ_ROOT_DIR)/XML/src/Event.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventDispatcher.sho : $(PRJ_ROOT_DIR)/XML/src/EventDispatcher.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventException.sho : $(PRJ_ROOT_DIR)/XML/src/EventException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventListener.sho : $(PRJ_ROOT_DIR)/XML/src/EventListener.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventTarget.sho : $(PRJ_ROOT_DIR)/XML/src/EventTarget.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/InputSource.sho : $(PRJ_ROOT_DIR)/XML/src/InputSource.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/LexicalHandler.sho : $(PRJ_ROOT_DIR)/XML/src/LexicalHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Locator.sho : $(PRJ_ROOT_DIR)/XML/src/Locator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/LocatorImpl.sho : $(PRJ_ROOT_DIR)/XML/src/LocatorImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/MutationEvent.sho : $(PRJ_ROOT_DIR)/XML/src/MutationEvent.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Name.sho : $(PRJ_ROOT_DIR)/XML/src/Name.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamePool.sho : $(PRJ_ROOT_DIR)/XML/src/NamePool.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamedNodeMap.sho : $(PRJ_ROOT_DIR)/XML/src/NamedNodeMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamespaceStrategy.sho : $(PRJ_ROOT_DIR)/XML/src/NamespaceStrategy.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamespaceSupport.sho : $(PRJ_ROOT_DIR)/XML/src/NamespaceSupport.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Node.sho : $(PRJ_ROOT_DIR)/XML/src/Node.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeAppender.sho : $(PRJ_ROOT_DIR)/XML/src/NodeAppender.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeFilter.sho : $(PRJ_ROOT_DIR)/XML/src/NodeFilter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeIterator.sho : $(PRJ_ROOT_DIR)/XML/src/NodeIterator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeList.sho : $(PRJ_ROOT_DIR)/XML/src/NodeList.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Notation.sho : $(PRJ_ROOT_DIR)/XML/src/Notation.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ParserEngine.sho : $(PRJ_ROOT_DIR)/XML/src/ParserEngine.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ProcessingInstruction.sho : $(PRJ_ROOT_DIR)/XML/src/ProcessingInstruction.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/SAXException.sho : $(PRJ_ROOT_DIR)/XML/src/SAXException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/SAXParser.sho : $(PRJ_ROOT_DIR)/XML/src/SAXParser.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Text.sho : $(PRJ_ROOT_DIR)/XML/src/Text.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/TreeWalker.sho : $(PRJ_ROOT_DIR)/XML/src/TreeWalker.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/WhitespaceFilter.sho : $(PRJ_ROOT_DIR)/XML/src/WhitespaceFilter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLException.sho : $(PRJ_ROOT_DIR)/XML/src/XMLException.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLFilter.sho : $(PRJ_ROOT_DIR)/XML/src/XMLFilter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLFilterImpl.sho : $(PRJ_ROOT_DIR)/XML/src/XMLFilterImpl.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLReader.sho : $(PRJ_ROOT_DIR)/XML/src/XMLReader.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLString.sho : $(PRJ_ROOT_DIR)/XML/src/XMLString.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLWriter.sho : $(PRJ_ROOT_DIR)/XML/src/XMLWriter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmlparse.sho : $(PRJ_ROOT_DIR)/XML/src/xmlparse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmlrole.sho : $(PRJ_ROOT_DIR)/XML/src/xmlrole.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok.sho : $(PRJ_ROOT_DIR)/XML/src/xmltok.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok_impl.sho : $(PRJ_ROOT_DIR)/XML/src/xmltok_impl.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok_ns.sho : $(PRJ_ROOT_DIR)/XML/src/xmltok_ns.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_POCO1.6 = POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ASCIIEncoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AbstractObserver.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ActiveDispatcher.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ArchiveStrategy.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Ascii.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AsyncChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AtomicCounter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base32Decoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base32Encoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base64Decoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base64Encoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/BinaryReader.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/BinaryWriter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Bugcheck.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ByteOrder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Channel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Checksum.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Clock.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Condition.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Configurable.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ConsoleChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/CountingStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTime.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeFormat.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeFormatter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeParser.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Debugger.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DeflatingStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DigestEngine.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DigestStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIterator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIteratorStrategy.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryWatcher.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Environment.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Error.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ErrorHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/EventArgs.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Exception.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FIFOBufferStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FPEnvironment.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/File.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStreamFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Format.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Formatter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FormattingChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Glob.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Hash.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HashStatistic.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HexBinaryDecoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HexBinaryEncoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/InflatingStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin1Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin2Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin9Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LineEndingConverter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LocalDateTime.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogFile.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Logger.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LoggingFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LoggingRegistry.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MD4Engine.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MD5Engine.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Manifest.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MemoryPool.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MemoryStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Message.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NestedDiagnosticContext.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Notification.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NotificationCenter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NotificationQueue.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NullChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NullStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumberFormatter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumberParser.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumericString.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Path.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PatternFormatter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Pipe.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PriorityNotificationQueue.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Process.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PurgeStrategy.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Random.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RandomStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RefCountedObject.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RegularExpression.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RotateStrategy.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Runnable.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SHA1Engine.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SignalHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SimpleFileChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SortedDirectoryIterator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SplitterChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Stopwatch.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamConverter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamCopier.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamTokenizer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/String.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StringTokenizer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SynchronizedObject.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SyslogChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Task.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TaskManager.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TaskNotification.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TeeStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TemporaryFile.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextBufferIterator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextConverter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextEncoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextIterator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Thread.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadLocal.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadPool.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadTarget.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TimedNotificationQueue.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timespan.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timestamp.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Token.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URI.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URIStreamFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URIStreamOpener.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF16Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF32Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF8Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF8String.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UUID.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UUIDGenerator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Unicode.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UnicodeConverter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Var.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/VarHolder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/VarIterator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Void.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1250Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1251Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1252Encoding.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/adler32.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/compress.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/crc32.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/deflate.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/infback.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inffast.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inflate.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inftrees.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_byte_order.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_chartables.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_compile.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_config.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_dfa_exec.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_exec.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_fullinfo.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_get.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_globals.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_jit_compile.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_maketables.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_newline.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_ord2utf8.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_refcount.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_string_utils.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_study.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_tables.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_ucd.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_valid_utf8.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_version.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_xclass.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/trees.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/zutil.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Array.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Handler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/JSONException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Object.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/ParseHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Parser.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/PrintHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Query.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Stringifier.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Template.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/TemplateCache.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/AbstractHTTPRequestHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DNS.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DatagramSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DatagramSocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DialogSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FTPClientSession.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FTPStreamFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FilePartSource.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTMLForm.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPAuthenticationParams.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPBasicCredentials.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPBufferAllocator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPChunkedStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPClientSession.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPCookie.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPCredentials.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPDigestCredentials.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPFixedLengthStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPHeaderStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPIOStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPMessage.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequest.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequestHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequestHandlerFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPResponse.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerConnection.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerConnectionFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerParams.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerRequest.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerRequestImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerResponse.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerResponseImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerSession.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSession.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSessionFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSessionInstantiator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPStreamFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HostEntry.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPClient.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPEventArgs.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPPacket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPPacketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPSocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPv4PacketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/IPAddress.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/IPAddressImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailMessage.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailRecipient.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MediaType.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MessageHeader.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MulticastSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MultipartReader.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MultipartWriter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPClient.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPEventArgs.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPPacket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NameValueCollection.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/Net.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NetException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NetworkInterface.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NullPartHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/OAuth10Credentials.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/OAuth20Credentials.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/POP3ClientSession.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartSource.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartStore.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/QuotedPrintableDecoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/QuotedPrintableEncoder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RawSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RawSocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RemoteSyslogChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RemoteSyslogListener.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SMTPChannel.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SMTPClientSession.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ServerSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ServerSocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/Socket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketAddress.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketAddressImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketNotification.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketNotifier.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketReactor.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketStream.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StreamSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StreamSocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StringPartSource.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerConnection.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerConnectionFactory.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerDispatcher.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerParams.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/WebSocket.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/WebSocketImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/AbstractConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Application.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ConfigurationMapper.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ConfigurationView.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/FilesystemConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/HelpFormatter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/IniFileConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/IntValidator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/JSONConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LayeredConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LoggingConfigurator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LoggingSubsystem.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/MapConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Option.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionCallback.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionProcessor.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionSet.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/PropertyFileConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/RegExpValidator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ServerApplication.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Subsystem.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/SystemConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Timer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/TimerTask.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Validator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/XMLConfiguration.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AbstractContainerNode.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AbstractNode.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Attr.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AttrMap.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Attributes.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AttributesImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/CDATASection.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/CharacterData.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ChildNodesList.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Comment.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ContentHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMBuilder.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMImplementation.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMObject.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMParser.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMSerializer.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMWriter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DTDHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DTDMap.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DeclHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DefaultHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Document.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentEvent.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentFragment.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentType.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Element.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ElementsByTagNameList.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Entity.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityReference.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityResolver.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityResolverImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ErrorHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Event.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventDispatcher.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventListener.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventTarget.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/InputSource.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/LexicalHandler.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Locator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/LocatorImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/MutationEvent.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Name.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamePool.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamedNodeMap.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamespaceStrategy.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamespaceSupport.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Node.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeAppender.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeFilter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeIterator.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeList.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Notation.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ParserEngine.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ProcessingInstruction.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/SAXException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/SAXParser.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Text.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/TreeWalker.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/WhitespaceFilter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLException.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLFilter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLFilterImpl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLReader.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLString.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLWriter.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmlparse.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmlrole.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok_impl.sho \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok_ns.sho

POCO1.6/$(MODE_DIR)/POCO1.6.so : $(OBJECTS_POCO1.6)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";SONAME=`basename ""$@""`;if [ "$(SHAREDLIB_VERSION)" != "" ]; then SONAME=$$SONAME.$(SHAREDLIB_VERSION);fi; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Shared-Library-Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -fpic -D__SO_PICABIRTP__ -shared -Wl,-soname,"$$SONAME" -o "$@" $(OBJECTS_POCO1.6) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/pentium/PENTIUM4/common/PIC $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi && if [ "$(SHAREDLIB_VERSION)" != "" ]; then cp -f "$@" "$@.$(SHAREDLIB_VERSION)";fi

POCO1.6/$(MODE_DIR)/POCO1.6_compile_file : $(FILE) ;

_clean :: POCO1.6/$(MODE_DIR)/POCO1.6_clean

POCO1.6/$(MODE_DIR)/POCO1.6_clean : 
	$(TRACE_FLAG)if [ -d "POCO1.6" ]; then cd "POCO1.6"; rm -rf $(MODE_DIR); fi

DEP_FILES := POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ASCIIEncoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AbstractObserver.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ActiveDispatcher.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ArchiveStrategy.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Ascii.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AsyncChannel.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/AtomicCounter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base32Decoder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base32Encoder.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base64Decoder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Base64Encoder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/BinaryReader.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/BinaryWriter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Bugcheck.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ByteOrder.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Channel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Checksum.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Clock.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Condition.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Configurable.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ConsoleChannel.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/CountingStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTime.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeFormat.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeFormatter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DateTimeParser.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Debugger.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DeflatingStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DigestEngine.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DigestStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIterator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIteratorStrategy.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryIterator_UNIX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/DirectoryWatcher.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Environment.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Environment_VX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Error.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ErrorHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/EventArgs.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event_POSIX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Event_VX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Exception.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FIFOBufferStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FPEnvironment.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FPEnvironment_C99.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/File.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileChannel.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStreamFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FileStream_POSIX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/File_VX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Format.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Formatter.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/FormattingChannel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Glob.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Hash.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HashStatistic.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HexBinaryDecoder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/HexBinaryEncoder.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/InflatingStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin1Encoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin2Encoding.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Latin9Encoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LineEndingConverter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LocalDateTime.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogFile.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogFile_STD.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LogStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Logger.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LoggingFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/LoggingRegistry.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MD4Engine.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MD5Engine.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Manifest.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MemoryPool.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/MemoryStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Message.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex_POSIX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Mutex_VX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent_Android.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedEvent_UNIX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex_Android.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NamedMutex_UNIX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NestedDiagnosticContext.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Notification.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NotificationCenter.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NotificationQueue.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NullChannel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NullStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumberFormatter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumberParser.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/NumericString.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Path.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Path_UNIX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PatternFormatter.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Pipe.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl_DUMMY.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeImpl_POSIX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PipeStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PriorityNotificationQueue.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Process.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Process_VX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/PurgeStrategy.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock_Android.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RWLock_VX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Random.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RandomStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RefCountedObject.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RegularExpression.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/RotateStrategy.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Runnable.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SHA1Engine.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore_POSIX.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Semaphore_VX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory_DUMMY.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SharedMemory_POSIX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SignalHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SimpleFileChannel.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SortedDirectoryIterator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SplitterChannel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Stopwatch.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamChannel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamConverter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamCopier.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StreamTokenizer.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/String.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/StringTokenizer.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SynchronizedObject.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/SyslogChannel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Task.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TaskManager.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TaskNotification.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TeeStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TemporaryFile.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextBufferIterator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextConverter.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextEncoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TextIterator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Thread.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadLocal.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadPool.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/ThreadTarget.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Thread_VX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/TimedNotificationQueue.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timer.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timespan.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timestamp.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone_UNIX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Timezone_VX.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Token.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URI.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URIStreamFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/URIStreamOpener.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF16Encoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF32Encoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF8Encoding.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UTF8String.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UUID.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UUIDGenerator.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Unicode.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/UnicodeConverter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Var.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/VarHolder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/VarIterator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Void.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1250Encoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1251Encoding.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/Windows1252Encoding.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/adler32.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/bignum-dtoa.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/bignum.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/cached-powers.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/compress.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/crc32.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/deflate.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/diy-fp.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/double-conversion.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/fast-dtoa.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/fixed-dtoa.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/infback.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inffast.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inflate.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/inftrees.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_byte_order.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_chartables.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_compile.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_config.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_dfa_exec.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_exec.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_fullinfo.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_get.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_globals.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_jit_compile.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_maketables.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_newline.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_ord2utf8.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_refcount.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_string_utils.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_study.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_tables.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_ucd.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_valid_utf8.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_version.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/pcre_xclass.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/strtod.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/trees.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Foundation/src/zutil.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Array.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Handler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/JSONException.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Object.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/ParseHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Parser.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/PrintHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Query.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Stringifier.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/Template.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/JSON/src/TemplateCache.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/AbstractHTTPRequestHandler.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DNS.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DatagramSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DatagramSocketImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/DialogSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FTPClientSession.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FTPStreamFactory.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/FilePartSource.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTMLForm.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPAuthenticationParams.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPBasicCredentials.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPBufferAllocator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPChunkedStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPClientSession.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPCookie.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPCredentials.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPDigestCredentials.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPFixedLengthStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPHeaderStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPIOStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPMessage.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequest.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequestHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPRequestHandlerFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPResponse.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServer.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerConnection.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerConnectionFactory.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerParams.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerRequest.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerRequestImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerResponse.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerResponseImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPServerSession.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSession.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSessionFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPSessionInstantiator.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HTTPStreamFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/HostEntry.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPClient.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPEventArgs.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPPacket.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPPacketImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPSocketImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ICMPv4PacketImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/IPAddress.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/IPAddressImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailMessage.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailRecipient.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MailStream.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MediaType.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MessageHeader.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MulticastSocket.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MultipartReader.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/MultipartWriter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPClient.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPEventArgs.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NTPPacket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NameValueCollection.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/Net.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NetException.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NetworkInterface.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/NullPartHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/OAuth10Credentials.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/OAuth20Credentials.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/POP3ClientSession.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartSource.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/PartStore.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/QuotedPrintableDecoder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/QuotedPrintableEncoder.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RawSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RawSocketImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RemoteSyslogChannel.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/RemoteSyslogListener.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SMTPChannel.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SMTPClientSession.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ServerSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/ServerSocketImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/Socket.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketAddress.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketAddressImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketNotification.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketNotifier.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketReactor.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/SocketStream.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StreamSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StreamSocketImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/StringPartSource.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServer.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerConnection.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerConnectionFactory.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerDispatcher.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/TCPServerParams.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/WebSocket.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Net/src/WebSocketImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/AbstractConfiguration.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Application.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ConfigurationMapper.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ConfigurationView.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/FilesystemConfiguration.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/HelpFormatter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/IniFileConfiguration.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/IntValidator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/JSONConfiguration.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LayeredConfiguration.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LoggingConfigurator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/LoggingSubsystem.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/MapConfiguration.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Option.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionCallback.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionException.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionProcessor.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/OptionSet.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/PropertyFileConfiguration.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/RegExpValidator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/ServerApplication.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Subsystem.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/SystemConfiguration.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Timer.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/TimerTask.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/Validator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/Util/src/XMLConfiguration.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AbstractContainerNode.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AbstractNode.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Attr.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AttrMap.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Attributes.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/AttributesImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/CDATASection.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/CharacterData.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ChildNodesList.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Comment.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ContentHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMBuilder.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMException.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMImplementation.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMObject.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMParser.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMSerializer.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DOMWriter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DTDHandler.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DTDMap.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DeclHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DefaultHandler.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Document.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentEvent.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentFragment.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/DocumentType.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Element.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ElementsByTagNameList.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Entity.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityReference.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityResolver.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EntityResolverImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ErrorHandler.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Event.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventDispatcher.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventException.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventListener.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/EventTarget.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/InputSource.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/LexicalHandler.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Locator.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/LocatorImpl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/MutationEvent.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Name.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamePool.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamedNodeMap.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamespaceStrategy.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NamespaceSupport.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Node.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeAppender.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeFilter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeIterator.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/NodeList.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Notation.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ParserEngine.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/ProcessingInstruction.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/SAXException.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/SAXParser.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/Text.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/TreeWalker.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/WhitespaceFilter.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLException.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLFilter.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLFilterImpl.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLReader.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLString.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/XMLWriter.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmlparse.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmlrole.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok.d \
	 POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok_impl.d POCO1.6/$(MODE_DIR)/Objects/POCO1.6/XML/src/xmltok_ns.d
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
