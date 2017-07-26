/* doublechar.c:  双字符组的使用 */

#include <stdio.h>


int main()
{
	int arr<::> = <% 10, 20, 30 %>;
	printf("The second array element is <%d>.\n", arr<:1:>);

	int arr2[] = { 10, 20, 30};
	printf("The second array element is <%d>.\n", arr2[1]);

	return 0;
}