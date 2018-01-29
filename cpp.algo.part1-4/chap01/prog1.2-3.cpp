#include <iostream>

using namespace std;

static const int N = 10;

void print(int *id, int n, int p, int q)
{
    cout << p << " " << q << "    ";
    for (int i = 0; i < N; i++)
        cout << id[i] << " ";
    cout << endl;
}

int main()
{
    int i, j, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;

    cout << "p q    0 1 2 3 4 5 6 7 8 9 \n" << endl;
    while (cin >> p >> q) { 
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) {
            print(id, N, p, q);
            continue;
        }

        id[i] = j;

        print(id, N, p, q);
    }
}

