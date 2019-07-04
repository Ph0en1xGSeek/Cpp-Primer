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
#include <map>

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
using std::remove_if;
using std::copy;
using std::size_t;
using std::map;
using std::pair;



int main() {
    map<string, list<int>> row_map;
    map<vector<int>::iterator, int> vim;
    map<list<int>::iterator, int>lim;

    vector<int> vi;
    list<int> li;

    vim.insert(pair<vector<int>::iterator, int>(vi.begin(), 0));

    // Warning!
    lim.insert(pair<list<int>::iterator, int>(li.begin(), 0));
    return 0;
}