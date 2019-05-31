#include <bits/stdc++.h>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main()
{
    using FP = decltype(add) *;
    vector<FP> v1;
    v1.push_back(add);
    v1.push_back(substract);
    v1.push_back(multiply);
    v1.push_back(divide);
    for(auto fun: v1) {
        cout << fun(3, 5) << endl;
    }
    return 0;
}
