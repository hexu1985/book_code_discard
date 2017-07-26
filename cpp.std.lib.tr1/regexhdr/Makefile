#my makefile

CC = g++
CFLAGS = -std=c++11 -Wall -c -g

TARGET = overview regexiter

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o *.exe 

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

overview: overview.o
	$(CC) -o $@ $^

regexiter: regexiter.o
	$(CC) -o $@ $^ 

	
