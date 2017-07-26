#
# Import includes
#
COMMON_INCLUDES  = -I./exports/

#
# Sources/objects
#
SRC_PATH         = ./src
OBJECTS          = $(SRC_PATH)/defaultVisibility.o

#
# Libraries
#
SYSLIBRARIES     = 			 \
		           -lpthread \
		           -lm       \
		           -ldl

LIBS             = $(SYSLIBRARIES)

SYSLDFLAGS       = -g

#
# Outputs
#
SHAREDLIB       = libdefaultvisibility.so
EXECUTABLE      = $(SHAREDLIB)

#
# Compiler
#
INCLUDES         = $(COMMON_INCLUDES)
DEBUG_CFLAGS     = -Wall -g -O0 
RELEASE_CFLAGS   = -Wall -O2

ifeq ($(DEBUG), 1)
CFLAGS           = $(DEBUG_CFLAGS) -fPIC $(INCLUDES)
else
CFLAGS           = $(RELEASE_CFLAGS) -fPIC $(INCLUDES)
endif

COMPILE          = g++ $(CFLAGS)

#
# Linker
#
LINK             = g++ -shared

#
# Build procedures/target descriptions
#
default: $(EXECUTABLE)

%.o: %.c
	$(COMPILE) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(LINK) $(OBJECTS) $(LIBS) -o $(EXECUTABLE)

clean:
	rm $(OBJECTS) $(EXECUTABLE)

