#include <bits/stdc++.h>

using namespace std;

int larger(const int num, const int *const iptr) {
    return (num > *iptr) ? num: *iptr;
}

int main()
{
    int b = 2;
    cout << larger(10, &b) << endl;
    return 0;
}
