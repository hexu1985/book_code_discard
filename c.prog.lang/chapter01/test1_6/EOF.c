#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    
    while (c = getchar() != EOF)
    	printf("%d\n", c);
    printf("%d - at EOF\n", c);
    
    system("PAUSE");	
    return 0;
}
