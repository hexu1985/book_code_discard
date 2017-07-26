/* Calc.h */

#ifndef CALC_H
#define CALC_H
 
#define NUMBER	1000		/* signal that a number was found */
#define NAME	1001		/* signal that a name was found */
#define COMMAND	1002		/* signal that a command was found */

int getop(char []);
void push(double);
double pop(void); 
int getch(void);
void ungetch(int); 
void clear(void);
void mathfnc(char []);
void cmdfnc(char []);

#endif 
