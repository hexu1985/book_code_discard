#my makefile

CC = g++
CFLAGS = -std=c++0x -Wall -c -g

TARGET = icase bicase

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(TARGET) *.exe 

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

icase: icase.o
	$(CC) -o $@ $^

bicase: bicase.o
	$(CC) -o $@ $^

	
