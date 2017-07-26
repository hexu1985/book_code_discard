g++ -Wall -g -O0 -I../shlibFirst -I../staticLib -c main.cpp
g++ main.o -ldl -L../staticLib -lsingleton -o clientApp
