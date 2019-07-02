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


map<string, size_t> count() {
    map<string, size_t> counts;
    for(string w; cin >> w; ++counts[w]);
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
    for(string w; cin >> w; ++counts[strip(w)]);
    return counts;
}

void print(const map<string, size_t>& counts) {
    for(const auto& kv: counts) {
        cout << kv.first << " : " << kv.second << endl;
    }
}

int main() {
    map<string, size_t> counts = count_with_strip();
    print(counts);
    return 0;
}