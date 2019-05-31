#include <bits/stdc++.h>

using namespace std;

void myswap(int *&ptr1, int *&ptr2) {
    int *tmp = ptr1;
    ptr1 = ptr2;
    ptr2 = tmp;
}

int main()
{
    int num1 = 1;
    int num2 = 2;
    int *a = &num1;
    int *b = &num2;
    cout << *a << " " << *b << endl;
    myswap(a, b);
    cout << *a << " " << *b << endl;
    return 0;
}
