#include "rgxutil.h"

int main()
{
	const char expr[] = "a*";
	match_ECMA(expr);
	match_grep(expr);
	match_ere(expr);

	match_ECMA("*");
	match_grep("*");
	match_ere("*");
	return 0;
}
