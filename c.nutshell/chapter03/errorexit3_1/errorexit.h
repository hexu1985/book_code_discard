/* errorexit.h:  ·¶Àýº¯Êýerror_exit() */

#ifndef ERROR_EXIT_H
#define ERROR_EXIT_H

#include <stdlib.h>
#include <stdio.h>

void error_exit(unsigned int error_n)
{
	char* error_msg[] = { "Unknown error code.\n",    
						  "Insufficient memory.\n", 
						  "Illegal memory access.\n" };
	unsigned int arr_len = sizeof(error_msg) / sizeof(char*);
	
	if ( error_n >= arr_len )
		error_n = 0;
	fputs( error_msg[error_n], stderr );
	exit(1);
}

#endif