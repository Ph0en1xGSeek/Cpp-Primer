#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

struct node {
    int a;
    int b;
    node(int a_, int b_) {
        a = a_;
        b = b_;
    }
    bool operator==(const node &s) const {
        return a == s.a && b == s.b;
    }
};

namespace std {
    template<>
    struct hash<node>
    {
        // typedef size_t result_type;
        // typedef node argument_type;
        size_t operator()(const node& s) const;
    };

    size_t hash<node>::operator()(const node &s) const {
        return hash<int>()(s.a) ^ hash<int>()(s.b);
    }
}



int main() {
    unordered_map<node, int> mp;
    mp[node(1,1)] = 1;
    mp[node(1,2)] = 2;
    cout << mp[node(1,1)] << endl;
    return 0;
}