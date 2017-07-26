#include <tr1/unordered_map>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>

using std::tr1::unordered_multimap;
using std::string;
using std::make_pair;
using std::pair;
using std::setw;
using std::setfill;
using std::copy;
using std::cout;
using std::basic_ostream;
using std::ostream_iterator;
using std::ios_base;
using std::ios;
using std::unary_function;

typedef unordered_multimap<string, string> dictionary;
typedef dictionary::value_type element;

static const char *pairs[] =
	{
	"day", 		"Tag",
	"strange", 	"fremd",
	"car", 		"Auto",
	"smart", 	"elegant",
	"trait", 	"Merkmal",
	"strange", 	"seltsam",
	"smart", 	"raffiniert",
	"smart", 	"klug",
	"clever", 	"raffiniert",
	0, 			0
	};

namespace std {

template <class Elem, class Traits>
basic_ostream<Elem, Traits> &operator <<(
		basic_ostream<Elem, Traits> &str, const element &elt)
{
	ios_base::fmtflags flags = str.flags();
	str.setf(ios::left, ios::adjustfield);
	str << ' ' << setw(10) << elt.first << elt.second;
	str.flags(flags);
	return str;
}

} // end namespace std

template <class InIt, class OutIt, class Pred>
OutIt copy_if(InIt first, InIt last, OutIt dest, Pred pr)
{
	for ( ; first != last; ++first, ++dest)
		if (pr(*first))
			*dest = *first;
	return dest;
}

struct equals: unary_function<element, bool>
{
	equals(const string &s): str(s) {}
	bool operator()(const element &elt) const
	{
		return elt.second == str;
	}

private:
	string str;
};

int main()
{
	dictionary dict;

	const char **cur = pairs;

	while (cur[0]) {
		dict.insert(make_pair(cur[0], cur[1]));
		cur += 2;
	}

	ostream_iterator<element> output(cout, "\n");
	cout << make_pair("Englist", "German") << '\n';
	cout << setfill('-') << setw(20) << ""
		<< setfill(' ') << '\n';

	copy(dict.begin(), dict.end(), output);

	string key("smart");
	cout << '\n' << key << ": \n";
	/* multimap 
	copy(dict.lower_bound(key), dict.upper_bound(key), output);
	*/
	pair<dictionary::iterator, dictionary::iterator> bound 
		= dict.equal_range(key);
	copy(bound.first, bound.second, output);

	string value("raffiniert");
	cout << '\n' << value << ": \n";
	copy_if(dict.begin(), dict.end(),
			output, equals(value));

	return 0;
}

