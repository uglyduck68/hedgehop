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
PRJ_ROOT_DIR := E:/DataRoom/ThreadPool/cthreadpool.tar



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = 
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

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 

IDE_LIBRARIES = 



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
PROJECT_TARGETS = ThreadPool/$(MODE_DIR)/ThreadPool.vxe


#Rules

# ThreadPool
ifeq ($(DEBUG_MODE),1)
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2  -fno-defer-pop
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2  -fno-defer-pop
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ThreadPool/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2  -fno-defer-pop
endif
ThreadPool/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
ThreadPool/$(MODE_DIR)/% : IDE_LIBRARIES = 
ThreadPool/$(MODE_DIR)/% : PROJECT_TYPE = RTP
ThreadPool/$(MODE_DIR)/% : DEFINES = 
ThreadPool/$(MODE_DIR)/% : DO_STRIP = 0
ThreadPool/$(MODE_DIR)/% : EXPAND_DBG = 0
ThreadPool/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
ThreadPool/$(MODE_DIR)/% : CPU = SIMPENTIUM
ThreadPool/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ThreadPool/$(MODE_DIR)/% : TOOL = gnu
ThreadPool/$(MODE_DIR)/% : TOOL_PATH = 
ThreadPool/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=i486 -march=i486
ThreadPool/$(MODE_DIR)/% : LIBPATH = 
ThreadPool/$(MODE_DIR)/% : LIBS = -lstdc++
ThreadPool/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
ThreadPool/$(MODE_DIR)/% : OBJ_DIR := ThreadPool/$(MODE_DIR)

ThreadPool/$(MODE_DIR)/Objects/ThreadPool/example.o : $(PRJ_ROOT_DIR)/example.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


ThreadPool/$(MODE_DIR)/Objects/ThreadPool/threadpool.o : $(PRJ_ROOT_DIR)/threadpool.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_ThreadPool = ThreadPool/$(MODE_DIR)/Objects/ThreadPool/example.o \
	 ThreadPool/$(MODE_DIR)/Objects/ThreadPool/threadpool.o

ThreadPool/$(MODE_DIR)/ThreadPool.vxe : $(OBJECTS_ThreadPool)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -Wall   -MD -MP -mrtp -o "$@" $(OBJECTS_ThreadPool) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS) -Wl,--start-group -Wl,--end-group && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

ThreadPool/$(MODE_DIR)/ThreadPool_compile_file : $(FILE) ;

_clean :: ThreadPool/$(MODE_DIR)/ThreadPool_clean

ThreadPool/$(MODE_DIR)/ThreadPool_clean : 
	$(TRACE_FLAG)if [ -d "ThreadPool" ]; then cd "ThreadPool"; rm -rf $(MODE_DIR); fi

DEP_FILES := ThreadPool/$(MODE_DIR)/Objects/ThreadPool/example.d ThreadPool/$(MODE_DIR)/Objects/ThreadPool/threadpool.d
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
