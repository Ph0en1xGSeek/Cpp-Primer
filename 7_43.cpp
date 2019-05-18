#include <bits/stdc++.h>

class NoDefault {
public:
    NoDefault(int num) {}
};

class C{
public:
    C(): n_def(0){};
private:
    NoDefault n_def;
};

int main() {
    C c;
    return 0;
}