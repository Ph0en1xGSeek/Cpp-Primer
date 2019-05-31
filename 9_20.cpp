#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <set>
#include <deque>
#include <stdio.h>

using namespace std;

int main() {
    list<int> li = {1,2,3,4,5,6,7,8,9,10};
    vector<int> odd, even;
    for(auto item: li) {
        ((item & 1) == 0 ? even: odd).push_back(item);
    }
    for(auto item: odd) {
        cout << item << ' ';
    }
    cout << endl;
    for(auto item: even) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}