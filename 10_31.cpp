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


int main() {
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vec(in_iter, eof);
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), out_iter);
    return 0;
}