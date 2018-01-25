#include <iostream>

using namespace std;

static const int N = 10;

int main()
{
    int i, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;

    cout << "p q    0 1 2 3 4 5 6 7 8 9 " << endl;
    while (cin >> p >> q) { 
        int t = id[p];
        if (t == id[q]) continue;
        for (i = 0; i < N; i++)
            if (id[i] == t) id[i] = id[q];

        cout << p << " " << q << "    ";
        for (i = 0; i < N; i++)
            cout << id[i] << " ";
        cout << endl;
    }
}

