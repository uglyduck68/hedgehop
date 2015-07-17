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

BUILD_SPEC = SIMPENTIUMgnu_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := E:/Works/2015/PlatformSW_TFT/platform/platform_src/trunk/Samples/OSWrapper/DateTime



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = -D_I7_VXWORKS_32
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpentium
CPU = SIMPENTIUM
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=i486 -march=i486
LIBPATH = 
LIBS = -lstdc++
VSB_DIR = $(WIND_BASE)/target/lib

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/h/sys -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Foundation/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/JSON/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Net/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Util/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/XML/include 

IDE_LIBRARIES = -L$(PLATFORM_SW_ROOT)/Lib/i7Vx32/Debug -lOSWrapper_i7VxSim32d 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2  -fno-defer-pop
DEBUGFLAGS_C++-Compiler = -O2  -fno-defer-pop
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2  -fno-defer-pop
endif


#Project Targets
PROJECT_TARGETS = SampleDateTime/$(MODE_DIR)/SampleDateTime.vxe


#Rules

# SampleDateTime
ifeq ($(DEBUG_MODE),1)
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2  -fno-defer-pop
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2  -fno-defer-pop
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SampleDateTime/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2  -fno-defer-pop
endif
SampleDateTime/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/h/sys -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Foundation/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/JSON/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Net/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Util/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/XML/include 
SampleDateTime/$(MODE_DIR)/% : IDE_LIBRARIES = -L$(PLATFORM_SW_ROOT)/Lib/i7Vx32/Debug -lOSWrapper_i7VxSim32d 
SampleDateTime/$(MODE_DIR)/% : PROJECT_TYPE = RTP
SampleDateTime/$(MODE_DIR)/% : DEFINES = -D_I7_VXWORKS_32
SampleDateTime/$(MODE_DIR)/% : DO_STRIP = 0
SampleDateTime/$(MODE_DIR)/% : EXPAND_DBG = 0
SampleDateTime/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
SampleDateTime/$(MODE_DIR)/% : CPU = SIMPENTIUM
SampleDateTime/$(MODE_DIR)/% : TOOL_FAMILY = gnu
SampleDateTime/$(MODE_DIR)/% : TOOL = gnu
SampleDateTime/$(MODE_DIR)/% : TOOL_PATH = 
SampleDateTime/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=i486 -march=i486
SampleDateTime/$(MODE_DIR)/% : LIBPATH = 
SampleDateTime/$(MODE_DIR)/% : LIBS = -lstdc++
SampleDateTime/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
SampleDateTime/$(MODE_DIR)/% : OBJ_DIR := SampleDateTime/$(MODE_DIR)

SampleDateTime/$(MODE_DIR)/Objects/SampleDateTime/src/DateTime.o : $(PRJ_ROOT_DIR)/src/DateTime.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_SampleDateTime = SampleDateTime/$(MODE_DIR)/Objects/SampleDateTime/src/DateTime.o

SampleDateTime/$(MODE_DIR)/SampleDateTime.vxe : $(OBJECTS_SampleDateTime)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -mrtp -o "$@" $(OBJECTS_SampleDateTime) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS) -Wl,--start-group -Wl,--end-group && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

SampleDateTime/$(MODE_DIR)/SampleDateTime_compile_file : $(FILE) ;

_clean :: SampleDateTime/$(MODE_DIR)/SampleDateTime_clean

SampleDateTime/$(MODE_DIR)/SampleDateTime_clean : 
	$(TRACE_FLAG)if [ -d "SampleDateTime" ]; then cd "SampleDateTime"; rm -rf $(MODE_DIR); fi

DEP_FILES := SampleDateTime/$(MODE_DIR)/Objects/SampleDateTime/src/DateTime.d
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
