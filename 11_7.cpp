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



int main() {
    map<string, vector<string> >family; 
    family["a"].push_back("b");
    family["a"].push_back("4");
    family["4"].push_back("kkkk");

    for(auto fam: family) {
        cout << "Last name: " << fam.first << ": ";
        for(auto ch: fam.second) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}