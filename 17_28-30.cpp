#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <bitset>
#include <regex>
#include <random>

using namespace std;

unsigned random_func() {
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u;
    return u(e);
}

unsigned random_func(unsigned i) {
    static default_random_engine e(i);
    static uniform_int_distribution<unsigned> u;
    return u(e);
}

unsigned random_func(unsigned i, unsigned min, unsigned max) {
    static default_random_engine e(i);
    static uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

int main() {
    
    cout << random_func(1) << endl;
    cout << random_func() << endl;
    for(int i = 0; i < 10; ++i) {
        cout << random_func(1, 0, 10) << " ";
    }
    cout << endl;
    return 0;
}