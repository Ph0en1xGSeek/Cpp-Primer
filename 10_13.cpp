#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

bool isLongerthan5(const string &s) {
    return s.size() > 5;
}

int main() {
    vector<string> vec = {"g", "asd", "ddfdfs", "ffff", "ddfdd", "a", "aauaaa"};
    auto largerPos = partition(vec.begin(), vec.end(), isLongerthan5);
    for(auto iter = vec.cbegin(); iter != largerPos; ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
}
 
 