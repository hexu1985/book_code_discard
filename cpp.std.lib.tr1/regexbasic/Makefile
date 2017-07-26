#my makefile

CC = g++
CFLAGS = -std=c++11 -Wall -c -g

TARGET = icase bicase construct assign swap markcount flags error

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(TARGET) *.exe *.o

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

icase: icase.o
	$(CC) -o $@ $^

bicase: bicase.o
	$(CC) -o $@ $^

construct: construct.o
	$(CC) -o $@ $^

assign: assign.o
	$(CC) -o $@ $^

swap: swap.o
	$(CC) -o $@ $^

markcount: markcount.o
	$(CC) -o $@ $^

flags: flags.o
	$(CC) -o $@ $^

error: error.o
	$(CC) -o $@ $^

	
