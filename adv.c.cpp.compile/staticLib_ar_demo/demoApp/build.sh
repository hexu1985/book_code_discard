gcc -Wall -I ../staticLib -c main.c
gcc main.o -L../staticLib -lmystaticlib -o demoApp
