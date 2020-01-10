#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <bitset>
#include <regex>

using namespace std;


int main() {
    
    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string format = "$2.$5.$7";
    regex r(pattern);
    string s;
    while(getline(cin, s)) {
        smatch result;
        regex_search(s, result, r);
        if(!result.empty()) {
            cout << result.prefix() << result.format(format) << endl;
        }else {
            cout << "Not matched" << endl;
        }
    }
    return 0;
}