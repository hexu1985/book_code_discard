#include <tr1/functional>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using std::tr1::hash;
using std::cout;
using std::string;
using std::vector;
using std::iterator_traits;

template <class InIt>
void show_hashes(InIt first, InIt last)
{
	typedef typename
		iterator_traits<InIt>::value_type type;
	hash<type> hasher;
	while (first != last)
		cout << hasher(*first++) << ' ';
	cout << '\n';
}

struct coord
{
	int x, y;
};

namespace std {
namespace tr1 {

template <>
struct hash<coord>
{
	std::size_t operator ()(const coord &val) const
	{
		hash<int> make_hash;
		return make_hash(val.x) + make_hash(val.y);
	}
};

}	// end tr1
}	// end std

#define SIZE(arr)	(sizeof (arr) / sizeof (*arr))

int main()
{
	int data[] = {1, 2, 3, 4, 5};
	show_hashes(data, data + SIZE(data));

	char *text[] = {"1", "2", "3", "4", "5"};
	vector<string> strings(text, text + SIZE(text));
	show_hashes(strings.begin(), strings.end());

	coord points[] =
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 2}};
	show_hashes(points, points + SIZE(points));

	return 0;
}

