#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <set>
#include <deque>
#include <stdio.h>

using namespace std;

int main() {
    list<string> li;
    string tmp_str;
    while(cin >> tmp_str) {
        li.push_back(tmp_str);
    }
    for(list<string>::iterator iter = li.begin(); iter != li.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}