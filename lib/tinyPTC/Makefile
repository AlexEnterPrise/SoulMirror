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
$(patsubst %.c,%.h,$(patsubst %.cpp,%.hpp,$(1)))
endef


APP 		:= libtinyptc.a
CCFLAGS		:= -Wall -pedantic
CFLAGS 		:= $(CCFLAGS)
CC 			:= g++
C 			:= gcc
AR 			:= ar
RANLIB 		:= ranlib
ARFLAGS 	:= -crs
MKDIR 		:= mkdir -p
SRC 		:= src
OBJ 		:= obj
LIBS 		:= -lX11 -lXext ##esta es con la de X11 hay que usar la de irrlicht ls /usr/lib | grep Irrlicht en la terminal


ifdef DEBUG
	CCFLAGS += -g
else 
	CCFLAGS += -O3
endif


ALLCPPS 	:= $(shell find $(SRC)/ -type f -iname *.cpp)

ALLCS 		:= $(shell find $(SRC)/ -type f -iname *.c)

SUBDIRS 	:= $(shell find $(SRC)/ -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
ALLOBJ 	:= $(foreach F,$(ALLCPPS) $(ALLCS),$(call C20,$(F)))



.PHONY: info

$(APP) : $(OBJSUBDIRS) $(ALLOBJ)
	$(AR) $(ARFLAGS) $(APP) $(ALLOBJ)
	$(RANLIB) $(APP)


$(foreach F,$(ALLCPPS),$(eval $(call COMPILER,$(CC),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILER,$(C),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS))))

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