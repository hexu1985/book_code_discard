#
# Import includes
#
COMMON_INCLUDES  = -I../staticLib/exports/

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
		           
STATIC_LIB_PATH  = ../deploy
STATIC_LIBRARY   = $(STATIC_LIB_PATH)/libstaticlinkingdemo.a
LIBS             = $(SYSLIBRARIES) $(STATIC_LIBRARY) -Wl,-Bdynamic

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
LINK             = g++ 

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
	
deploy:
	make clean; make; cp $(EXECUTABLE) ../;
