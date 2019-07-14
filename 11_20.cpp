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


map<string, size_t> count() {
    map<string, size_t> counts;
    for(string w; cin >> w;) {
        pair<string, size_t> w_pair = make_pair(w, 1);
        auto ret = counts.insert(w_pair);
        if(ret.second == false) {
            ++ret.first->second;
        }
    }
    return counts;
}


const string& strip(string &str) {
    for(auto&ch : str) {
        ch = tolower(ch);
    }
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

map<string, size_t> count_with_strip() {
    map<string, size_t> counts;
    for(string w; cin >> w;) {
        w = strip(w);
        pair<string, size_t> w_pair = make_pair(w, 1);
        auto ret = counts.insert(w_pair);
        if(ret.second == false) {
            ++ret.first->second;
        }
    }
    return counts;
}

void print(const map<string, size_t>& counts) {
    for(const auto& kv: counts) {
        cout << kv.first << " : " << kv.second << endl;
    }
}

int main() {
    map<string, size_t> counts = count();
    print(counts);
    return 0;
}