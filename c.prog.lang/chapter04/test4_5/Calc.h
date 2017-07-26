/* Calc.h */

#ifndef CALC_H
#define CALC_H
 
#define NUMBER	'0'		/* signal that a number was found */
#define NAME	'n'		/* signal that a name was found */

int getop(char []);
void push(double);
double pop(void); 
int getch(void);
void ungetch(int); 
void mathfnc(char []);

#endif 
