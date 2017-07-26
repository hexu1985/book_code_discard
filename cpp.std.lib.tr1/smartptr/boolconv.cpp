#include <tr1/memory>
#include <iostream>

using std::tr1::shared_ptr;
using std::cout;
using std::string;

typedef shared_ptr<string> stp;

void show(stp s)
{
	if (s)
		cout << "string holds '" << *s << "'\n";
	else
		cout << "string is empty\n";
}

int main()
{
	stp s;
	show(s);
	s.reset(new string("Hello, world"));
	show(s);
	stp p((string *) 0);
	show(p);

	return 0;
}
