#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std::placeholders;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isLonger(const string &s, size_t sz) {
    return s.size() > sz;
}

int main() {
    vector<string> vec = {"g", "asd", "ddfdfs", "ffff", "ddfdd", "a", "aauaaa"};
    auto cnt = count_if(vec.begin(), vec.end(), bind(isLonger, _1, 5));
    
    cout << cnt << endl;
}