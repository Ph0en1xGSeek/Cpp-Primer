#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    list<string> strs;
    string tmp;
    string target = "Hello";
    while(cin >> tmp) {
        strs.push_back(tmp);
    }
    int cnt = count(strs.cbegin(), strs.cend(), target);
    cout << cnt << endl;
    return 0;
}
