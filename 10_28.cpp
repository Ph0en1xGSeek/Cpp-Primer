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
    vector<int> vec = {1,2,3,4,5,6};

    list<int> li;
    copy(vec.begin(), vec.end(), back_inserter(li));
    for(auto item: li) {
        cout << item << ' ';
    }
    cout << endl;

    list<int> li2;
    copy(vec.begin(), vec.end(), front_inserter(li2));
    for(auto item: li2) {
        cout << item << ' ';
    }
    cout << endl;

    list<int> li3;
    copy(vec.begin(), vec.end(), inserter(li3, li3.begin()));
    for(auto item: li3) {
        cout << item << ' ';
    }
    cout << endl;
}