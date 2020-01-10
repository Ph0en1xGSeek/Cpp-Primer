#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
ostream& print(ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... args) {
    os << t << ", ";
    return print(os, args...);
}

int main() {
    print(cout, 1, "dfdf", 3.4);
    return 0;
}