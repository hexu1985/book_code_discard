#
# Import includes
#
COMMON_INCLUDES  = -I./exports/

#
# Sources/objects
#
SRC_PATH         = ./src
OBJECTS          = $(SRC_PATH)/testStaticLinking.o

#
# Outputs
#
STATIC_LIBRARY   = libstaticlinkingdemo.a
OUTPUT           = $(STATIC_LIBRARY)

#
# Compiler
#
INCLUDES         = $(COMMON_INCLUDES)
DEBUG_CFLAGS     = -Wall -g -O0
RELEASE_CFLAGS   = -Wall -O2

ifeq ($(DEBUG), 1)
CFLAGS           = $(DEBUG_CFLAGS) -mcmodel=large $(INCLUDES)
else
CFLAGS           = $(RELEASE_CFLAGS) -mcmodel=large $(INCLUDES)
endif

COMPILE          = g++ $(CFLAGS)

#
# Archiver
#
ARCHIVE          = ar rcs

#
# Build procedures/target descriptions
#
DEPLOY_PATH      = ../deploy/

default: $(OUTPUT)

%.o: %.c
	$(COMPILE) -c $< -o $@

$(OUTPUT): $(OBJECTS)
	$(ARCHIVE) $(OUTPUT) $(OBJECTS)

clean:
	rm $(OBJECTS) $(STATIC_LIBRARY)

deploy:
	make clean; make; cp $(OUTPUT) $(DEPLOY_PATH);


