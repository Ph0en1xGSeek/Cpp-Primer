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

bool check_size(const string &s, size_t sz) {
    return s.size() < sz;
}

int main() {
    vector<int> vec = {2,3,5,1,6,4};
    string str("1111");
    auto res = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));
    
    if(res != vec.end()) {
        cout << *res << endl;
    }
}