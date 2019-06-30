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
using std::istream_iterator;
using std::ostream_iterator;
using std::find;
using std::copy;


int main() {
    vector<int> vec{1, 2, 3, 0, 4, 5, 0};
    for(vector<int>::reverse_iterator riter = vec.rbegin(); riter != vec.rend(); ++riter) {
        cout << *riter << ' ';
    }
    cout << endl;

    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    auto zero_iter = find(vec.crbegin(), vec.crend(), 0);
    if(zero_iter != vec.crend()) {
        cout << *zero_iter << endl;
    }

    vector<int> vec2{0,1,2,3,4,5,6,7,8,9};
    vector<int> copy_vec(5);
    copy(vec2.cbegin() + 3, vec2.cbegin() + 8, copy_vec.rbegin());
    for(auto item: copy_vec) {
        cout << item << ' ';
    }
    cout << endl;

    return 0;
}