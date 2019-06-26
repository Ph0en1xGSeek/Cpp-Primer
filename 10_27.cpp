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
using std::vector;
using std::string;
using std::list;


int main() {
    vector<int> vec = {1,2,1,5,3,4,5,6,6,6,5};
    list<int> li;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(li));
    for(auto item: li) {
        cout << item << ' ';
    }
    cout << endl;
}