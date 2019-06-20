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
    auto cnt = count_if(vec.begin(), vec.end(), [](const string &s)->bool{return s.size() > 5;});
    
    cout << cnt << endl;
}