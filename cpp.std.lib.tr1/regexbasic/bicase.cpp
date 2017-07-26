#include <regex>
#include <iostream>

using std::regex;
using std::regex_match;
using namespace std::regex_constants;
using std::cout;

static void match(const char *title,
		const char *expr, const char *tgt,
		syntax_option_type flags)
{
	regex rgx(expr, flags);
	cout << '`' << expr << "` (" << title << "): ";
	if (regex_match(tgt, rgx))
		cout << "matched";
	else
		cout << "didn't match";
	cout << " `" << tgt << "`\n";
}

static void match4(const char *title, const char *expr,
		syntax_option_type flags)
{
	match(title, expr, "a", flags);
	match(title, expr, "\x61", flags);
	match(title, expr, "A", flags);
	match(title, expr, "\x41", flags);
}

int main()
{
	match4("case sensitive", "a", grep);
	match4("case insensitive", "a", grep | icase);
	match4("case sensitive", "[a-c]", grep);
	match4("case insensitive", "[a-c]", grep | icase);

	return 0;
}

