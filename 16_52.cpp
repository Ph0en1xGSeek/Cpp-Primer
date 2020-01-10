#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

template<typename T, typename... Args>
void foo(T &t, const Args&... args) {
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;
}

int main() {
    int i = 0;
    double d = 3.14;
    string s = "hello world";
    foo(i, d, 42, s);
    foo(i, 42, d);
    foo(i, 42, 42);
    foo(d);
    return 0;
}