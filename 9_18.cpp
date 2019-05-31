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
    deque<string> dq;
    string tmp_str;
    while(cin >> tmp_str) {
        dq.push_back(tmp_str);
    }
    for(deque<string>::iterator iter = dq.begin(); iter != dq.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}