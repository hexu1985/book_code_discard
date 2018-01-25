#include <iostream>

using namespace std;

static const int N = 10;

int main()
{
    int i, j, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;

    cout << "p q    0 1 2 3 4 5 6 7 8 9 " << endl;
    while (cin >> p >> q) { 
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) continue;
        id[i] = j;

        cout << p << " " << q << "    ";
        for (i = 0; i < N; i++)
            cout << id[i] << " ";
        cout << endl;
    }
}

