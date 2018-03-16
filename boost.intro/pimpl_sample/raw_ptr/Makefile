
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -DNDEBUG 
INCLUDES =
LDFLAGS = 
LDPATH =
VPATH = 

SOURCES = $(shell ls *.cpp)
PROGS = pimpl_sample

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

$(PROGS): $(SOURCES) $(LIB_SOURCES)
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
