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
PRJ_ROOT_DIR := E:/Works/2015/PlatformSW_TFT/platform/platform_src/trunk/Samples/OSWrapper/Timer



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

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Foundation/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/JSON/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Net/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Util/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/XML/include 

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
PROJECT_TARGETS = SampleTimer/$(MODE_DIR)/SampleTimer.vxe


#Rules

# SampleTimer
ifeq ($(DEBUG_MODE),1)
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2  -fno-defer-pop
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2  -fno-defer-pop
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SampleTimer/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2  -fno-defer-pop
endif
SampleTimer/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn -I$(WIND_BASE)/target/usr/h/wrn/coreip -I$(WIND_BASE)/target/usr/h/wrn/coreip/sys -I$(WIND_HOME)/components/ip_net2-6.8/vxcompat/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Foundation/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/JSON/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Net/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/Util/include -I$(PLATFORM_SW_INCLUDE)/OSWrapper/XML/include 
SampleTimer/$(MODE_DIR)/% : IDE_LIBRARIES = -L$(PLATFORM_SW_ROOT)/Lib/i7Vx32/Debug -lOSWrapper_i7VxSim32d 
SampleTimer/$(MODE_DIR)/% : PROJECT_TYPE = RTP
SampleTimer/$(MODE_DIR)/% : DEFINES = -D_I7_VXWORKS_32
SampleTimer/$(MODE_DIR)/% : DO_STRIP = 0
SampleTimer/$(MODE_DIR)/% : EXPAND_DBG = 0
SampleTimer/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
SampleTimer/$(MODE_DIR)/% : CPU = SIMPENTIUM
SampleTimer/$(MODE_DIR)/% : TOOL_FAMILY = gnu
SampleTimer/$(MODE_DIR)/% : TOOL = gnu
SampleTimer/$(MODE_DIR)/% : TOOL_PATH = 
SampleTimer/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=i486 -march=i486
SampleTimer/$(MODE_DIR)/% : LIBPATH = 
SampleTimer/$(MODE_DIR)/% : LIBS = -lstdc++
SampleTimer/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
SampleTimer/$(MODE_DIR)/% : OBJ_DIR := SampleTimer/$(MODE_DIR)

SampleTimer/$(MODE_DIR)/Objects/SampleTimer/Src/Timer.o : $(PRJ_ROOT_DIR)/Src/Timer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_SampleTimer = SampleTimer/$(MODE_DIR)/Objects/SampleTimer/Src/Timer.o

SampleTimer/$(MODE_DIR)/SampleTimer.vxe : $(OBJECTS_SampleTimer)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -mrtp -o "$@" $(OBJECTS_SampleTimer) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS) -Wl,--start-group -Wl,--end-group && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

SampleTimer/$(MODE_DIR)/SampleTimer_compile_file : $(FILE) ;

_clean :: SampleTimer/$(MODE_DIR)/SampleTimer_clean

SampleTimer/$(MODE_DIR)/SampleTimer_clean : 
	$(TRACE_FLAG)if [ -d "SampleTimer" ]; then cd "SampleTimer"; rm -rf $(MODE_DIR); fi

DEP_FILES := SampleTimer/$(MODE_DIR)/Objects/SampleTimer/Src/Timer.d
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
