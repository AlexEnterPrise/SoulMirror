##############################################
####	MACROS
##############################################

define COMPILER
$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef



define C20
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef

define C2H
$(patsubst %.c,%.h,$(patsubst %.cpp,%.h,$(patsubst %.cpp,%.hpp,$(1))))
endef

ifeq (${CONFIG}, Debug)
    FLAGS += -g
    SUFFIX = L
else
    override CONFIG = Release
    FLAGS += -O2
    SUFFIX =
endif


#
APP 		:= soulMirror
CPU 		:= x86_64
CCFLAGS		:= -Wall -pedantic -O2 -m64 -std=c++17
CFLAGS 		:= $(CCFLAGS)
CC 		:= g++ -pthread
C 		:= gcc
MKDIR 		:= mkdir -p
SRC 		:= src
OBJ 		:= obj
LIBDIR 		:= lib
IrrlichtHome	:= lib/irrlicht/src
Core		:= core
Studio		:= studio
FMODHome 	:= lib/apiFMOD
LOWLEVEL_LIB 	:= lib/apiFMOD/core/lib/${CPU}/libfmod${SUFFIX}.so
STUDIO_LIB 	:= lib/apiFMOD/studio/lib/${CPU}/libfmodstudio${SUFFIX}.so
LIBS 		:= lib/irrlicht/irrlicht.a -lX11 -lXext -lIrrlicht -Wl,-rpath=\$$ORIGIN/$(dir ${LOWLEVEL_LIB}),-rpath=\$$ORIGIN/$(dir ${STUDIO_LIB}) ${LOWLEVEL_LIB} ${STUDIO_LIB}
INCDIRS		:= -I$(SRC) -I$(LIBDIR) -I$(IrrlichtHome)/include -L$(IrrlichtHome)/lib/$(SYSTEM) -lIrrlicht -I$(FMODHome)/$(Core)/inc -I$(FMODHome)/$(Studio)/inc -I$(FMODHome)/$(Core)/inc 

ifdef DEBUG
	CCFLAGS += -g
else 
	CCFLAGS += -O3
endif


ALLCPPS 	:= $(shell find $(SRC)/ -type f -iname *.cpp)

ALLCS 		:= $(shell find $(SRC)/ -type f -iname *.c)

SUBDIRS 	:= $(shell find $(SRC)/ -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
ALLOBJ 		:= $(foreach F,$(ALLCPPS) $(ALLCS),$(call C20,$(F)))



.PHONY: info

$(APP) : $(OBJSUBDIRS) $(ALLOBJ)
	$(CC) -o $(APP) $(ALLOBJ) $(LIBS)


$(foreach F,$(ALLCPPS),$(eval $(call COMPILER,$(CC),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS) $(INCDIRS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILER,$(C),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS) $(INCDIRS))))

#$(OBJ)/%.o : $(SRC)/%.c
#	$(C) -o $(patsubst $(SRC)%, $(OBJ)%,$@) -c $^ $(CFLAGS)

#$(OBJ)/%.o : $(SRC)/%.cpp
#	$(CC) -o $(patsubst $(SRC)%, $(OBJ)%,$@) -c $^ $(CCFLAGS)

info : 
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJ))

$(OBJSUBDIRS) : 
	$(MKDIR) $(OBJSUBDIRS)

clean:
	$(RM) -r "./$(OBJ)"

cleanall: clean
	$(RM) "./$(APP)"
