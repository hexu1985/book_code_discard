#
# Import includes
#
COMMON_INCLUDES  = -I../sharedLib/exports/

#
# Sources/objects
#
SRC_PATH         = ./src
OBJECTS          = $(SRC_PATH)/main.o

#
# Libraries
#
SYSLIBRARIES     = 			 \
		           -lpthread \
		           -lm       \
		           -ldl
		           
DEMOLIB_PATH     = ../deploy
DEMO_LIBRARY     = -L$(DEMOLIB_PATH) -lexecutablesharedlib
LIBS             = $(SYSLIBRARIES) $(DEMO_LIBRARY) -Wl,-Bdynamic

#
# Outputs
#
EXECUTABLE       = demoApp

#
# Compiler
#
INCLUDES         = $(COMMON_INCLUDES)
DEBUG_CFLAGS     = -Wall -g -O0
RELEASE_CFLAGS   = -Wall -O2

ifeq ($(DEBUG), 1)
CFLAGS           = $(DEBUG_CFLAGS) $(INCLUDES)
else
CFLAGS           = $(RELEASE_CFLAGS) $(INCLUDES)
endif

COMPILE          = g++ $(CFLAGS)

#
# Linker
#
RUNTIME_LIB_PATH = -Wl,-R$(DEMOLIB_PATH)
LINK             = g++ 

#
# Build procedures/target descriptions
#

default: $(EXECUTABLE)

%.o: %.c
	$(COMPILE) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(LINK) $(OBJECTS) $(LIBS) $(RUNTIME_LIB_PATH) -o $(EXECUTABLE)

clean:
	rm $(OBJECTS) $(EXECUTABLE)
	
deploy:
	make clean; make; patchelf --set-rpath ../deploy:./deploy $(EXECUTABLE); cp $(EXECUTABLE) ../;
