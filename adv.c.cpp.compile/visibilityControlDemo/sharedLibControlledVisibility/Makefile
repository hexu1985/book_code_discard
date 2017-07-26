#
# Import includes
#
COMMON_INCLUDES  = -I./exports/

#
# Sources/objects
#
SRC_PATH         = ./src
OBJECTS          = $(SRC_PATH)/testControlledVisibility.o

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
SHAREDLIB       = libcontrolledvisibility.so
EXECUTABLE      = $(SHAREDLIB)

#
# Compiler
#
INCLUDES         = $(COMMON_INCLUDES)
DEBUG_CFLAGS     = -Wall -g -O0
RELEASE_CFLAGS   = -Wall -O2
VISIBILITY_FLAGS = -fvisibility=hidden -fvisibility-inlines-hidden

ifeq ($(DEBUG), 1)
CFLAGS           = $(DEBUG_CFLAGS) -fPIC $(INCLUDES)
else
CFLAGS           = $(RELEASE_CFLAGS) -fPIC $(INCLUDES)
endif

CFLAGS          += $(VISIBILITY_FLAGS)

COMPILE          = g++ $(CFLAGS)

#
# Linker
#
LINK             = g++ -shared

#
# Build procedures/target descriptions
#
DEPLOY_PATH      = ../deploy/

default: $(EXECUTABLE)

%.o: %.c
	$(COMPILE) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(LINK) $(OBJECTS) $(LIBS) -o $(EXECUTABLE)

clean:
	rm $(OBJECTS) $(EXECUTABLE)

deploy:
	make clean; make; cp $(EXECUTABLE) $(DEPLOY_PATH);


