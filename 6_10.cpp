#include <bits/stdc++.h>

using namespace std;

void myswap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 0;
    int b = 1;
    cout << a << ' ' << b << endl;
    myswap(&a, &b);
    cout << a << ' ' << b << endl;

    return 0;
}
