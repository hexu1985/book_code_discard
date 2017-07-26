#my makefile

CC = g++
CFLAGS = -std=c++11 -Wall -c -g

TARGET = check match

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(TARGET) *.exe *.o

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

check: check.o
	$(CC) -o $@ $^

match: match.o
	$(CC) -o $@ $^

	
