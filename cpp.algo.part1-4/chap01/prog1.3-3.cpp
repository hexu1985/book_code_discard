#include <iostream>
#include "common.h"

using namespace std;

static const int N = 10;

int main()
{ 
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++) { 
        id[i] = i; sz[i] = 1; 
    }

    cout << "p q    0 1 2 3 4 5 6 7 8 9 \n" << endl;
    while (cin >> p >> q) { 
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) {
            cout << p << " " << q << "    ";
            print(id, N);
            continue;
        }
        if (sz[i] < sz[j]) { 
            id[i] = j; sz[j] += sz[i]; 
        } else { 
            id[j] = i; sz[i] += sz[j]; 
        }

        cout << p << " " << q << "    ";
        print(id, N);
    }
}

