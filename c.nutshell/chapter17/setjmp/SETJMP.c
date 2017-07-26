#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <errno.h>

double calculate1(double x);
double calculate2(double x);

jmp_buf jmp_dest;

int main()
{
	double x = 0, y1, y2;
	int n = 0;

	puts("--- Demonstrating non-local jumps ---\n");

	switch(setjmp(jmp_dest))
	{
	case 0:
		break;
	case EDOM:
		puts("Domain error. "
			 "Negative numbers are not permitted.");
		break;
	case ERANGE:
		puts("Range error. "
			 "The numbe you entered is too big.");
		break;
	default:
		puts("Unkown error.");
		exit(EXIT_FAILURE);
	}

	printf("Enter a number: ");
	do 
	{
		if ((n = scanf("%lf", &x)) < 0)
			exit(EXIT_FAILURE);
		while (getchar() != '\n')
			;
		if (n == 0)
			printf("Invalid entry. Try again: ");
	} while(n == 0);

	y1 = calculate1(x);
	y2 = calculate2(x);

	printf("\nResult of Calculation 1: %G\n", y1);
	printf("Result of Calculation 2: %G\n", y2);

	return 0;	
}