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
using std::make_pair;



int main() {
    map<int, string> mp;
    mp[0] = "Pan";
    cout << mp[0] << endl;
    map<int, string>::iterator it = mp.begin();
    it->second = "H";
    cout << mp[0] << endl;
    return 0;
}