##############################################
####	MACROS
##############################################

define COMPILER
$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

define C20
$(patsubst %.cpp,%.d,$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1)))))
endef

define C2H
$(patsubst %.cpp,%.d,$(patsubst %.c,%.h,$(patsubst %.cpp,%.h,$(1))))
endef

CPPFLAGS = -I$(IrrlichtHome)/include -I/usr/X11R6/include $(USERCPPFLAGS)
CXXFLAGS = $(USERCXXFLAGS)
LDFLAGS = $(USERLDFLAGS)

CPPFLAGS = -I$(SRC)/include -I/usr/X11R6/include -I/usr/include/freetype2/ -I/usr/X11R6/include 
CXXFLAGS = -ffast-math 
all_linux all_macos all_win32 static_win32: LDFLAGS += -L$(IrrlichtHome)/lib/$(SYSTEM) -lIrrlicht
all_linux: LDFLAGS += -L/usr/X11R6/lib$(LIBSELECT) -lGL -lXxf86vm -lXext -lX11 -lXcursor
all_linux clean_linux: SYSTEM=Linux
all_macos: LDFLAGS += -Xlinker -no_pie -framework OpenGL -framework Cocoa -framework Carbon -framework IOKit



APP 		:= irrlicht.a
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


ifdef DEBUG
	CCFLAGS += -g 
else 
	CCFLAGS += -O3 $(CPPFLAGS) 
endif


ALLCPPS 	:= $(shell find $(SRC)/ -type f -iname *.cpp)

ALLCS 		:= $(shell find $(SRC)/ -type f -iname *.c)

SUBDIRS 	:= $(shell find $(SRC)/ -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
ALLOBJ 	:= $(foreach F,$(ALLCPPS) $(ALLCS),$(call C20,$(F)))



.PHONY: info

$(APP) : $(OBJSUBDIRS) $(ALLOBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Sources) -o $(DESTPATH) $(LDFLAGS)
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