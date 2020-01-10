#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;


template<typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
    f(forward<T2>(t2), forward<T1>(t1));
} 

void func_lvalue(string &lhs, string &rhs) {
    lhs = "changed_lhs\n";
    rhs = "changed_rhs\n";
}

void func_rvalue(int &&lhs, int &&rhs) {
    allocator<int> alloc;
    int *data = alloc.allocate(3);
    alloc.construct(data, lhs);
    alloc.construct(data + 1, 0);
    alloc.construct(data + 2, rhs);
    for(auto p = data; p != data + 3; ++p) {
        cout << *p << endl;
    }

    for (auto p = data + 3; p != data; ) {
        alloc.destroy(--p);
    }

    alloc.deallocate(data, 3);
}


int main() {
    string s1, s2;
    flip(func_lvalue, s1, s2);
    cout << s1 << s2 << endl;

    flip(func_rvalue, 88, 99);
    return 0;
}