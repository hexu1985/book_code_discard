#include <iostream>
#include "common.h"

using namespace std;

static const int N = 10;

int main()
{
    int i, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;

    cout << "p q    0 1 2 3 4 5 6 7 8 9 \n" << endl;
    while (cin >> p >> q) { 
        int t = id[p];
        if (t == id[q]) {
            cout << p << " " << q << "    ";
            print(id, N);
            continue;
        }
        for (i = 0; i < N; i++)
            if (id[i] == t) id[i] = id[q];

        cout << p << " " << q << "    ";
        print(id, N);
    }
}

