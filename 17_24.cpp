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
        cout << regex_replace(s, r, format) << endl;
        cout << regex_replace(s, r, format, regex_constants::format_no_copy) << endl;
    }
    return 0;
}