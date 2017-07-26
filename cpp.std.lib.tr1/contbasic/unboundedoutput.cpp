#include <iostream>
#include <iterator>

using std::iterator;
using std::output_iterator_tag;
using std::cout;

struct write_iter: iterator<output_iterator_tag, int>
{
    struct writer
    {
        template <class Ty> writer &operator=(const Ty &val)
        {
            cout << val << ' ';
            return *this;
        }
    };

    writer operator *() const
    {
        return writer();
    }

    write_iter &operator ++()
    {
        return *this;
    }

    const write_iter &operator ++(int)
    {
        return *this;
    }
};

template <class Iter>
void setcount(Iter first, int count)
{
    for (int i = 0; i < count; ++i)
        *first++ = i;
}

int main()
{
    const int NVALS = 6;
    setcount(write_iter(), NVALS);

    return 0;
}
