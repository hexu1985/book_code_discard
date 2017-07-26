#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>

void sigint_handler(int sig);
volatile sig_atomic_t i;

int main()
{
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		perror("Failed to install SIGINT hander");
		exit(3);
	}

	while (1)
	{
		puts("Press Ctrl+C to interrupt me.");
		for (i = 0; i < SIG_ATOMIC_MAX; i++)
			if (i % 100000 == 0)
			{
				printf("\r%d", i / 100000);
				fflush(stdout);
			}
		raise(SIGINT);
	}
	return 0;
}

void sigint_handler(int sig)
{
	char c;

	if (sig != SIGINT) exit(1);

	signal(SIGINT, SIG_IGN);

	puts("\nThis is the function sigint_handler()."
		 "\nDo you want to exit the program now? [y/n]");
	while ((c = tolower(getchar())) != 'y' && c != 'n')
		;

	if (c == 'y')
		exit(0);
	else
		i = 0;
	signal(SIGINT, sigint_handler);
}