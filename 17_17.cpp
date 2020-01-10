#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <bitset>
#include <regex>

using namespace std;



int main() {
    
    try{
        regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
        vector<string> vstr({"ab.cpp", "cc.c"});
        smatch results;
        for(string elem: vstr) {
            if(regex_search(elem, results, r)) {
                cout << results.str() << endl;
            }
        } 
    }catch(regex_error e) {
        cout << e.what() << endl;
    }

    regex r2("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    string str;
    smatch results;

    // while(cin >> str) {
    //     if(regex_match(str, results, r2)) {
    //         cout << "violate" << endl;
    //     }else {
    //         cout << "right" << endl;
    //     }
    // }

    r2.assign("[^c]ei");

    while(cin >> str) {
        for(sregex_iterator it(str.begin(), str.end(), r2), it_end; it != it_end; ++it) {
            cout << it->str() << endl;
        }
    }




    return 0;
}