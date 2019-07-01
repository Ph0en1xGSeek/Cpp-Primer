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
#include <iterator>

using namespace std::placeholders;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::forward_list;
using std::istream_iterator;
using std::ostream_iterator;
using std::find;
using std::copy;


void elimDumps(list<string> &li) {
    li.sort();
    li.unique();
}


int main() {
    list<string> li = {"13345", "sdfdf", "abc", "3333", "abc", "3333"};
    elimDumps(li);
    for(auto item: li) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}