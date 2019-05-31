#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <set>
#include <stdio.h>

using namespace std;

int main() {
    list<const char*> l = {"aaa", "bbb", "ccc"};
    vector<string> vec;
    vec.assign(l.begin(), l.end());
    for(auto str: vec) {
        cout << str << endl;
    }
    return 0;
}