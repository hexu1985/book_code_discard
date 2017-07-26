#include <stdio.h>

int function_with_duplicated_name(int x)
{
    printf("%s\n", __FUNCTION__);
    return 0;	
}

int function_with_duplicated_name(int x, int y)
{
    printf("%s\n", __FUNCTION__);
    return 0;	
}

int main(int argc, char* argv[])
{
    function_with_duplicated_name(1);
    function_with_duplicated_name(1,2);
    return 0;	
}
