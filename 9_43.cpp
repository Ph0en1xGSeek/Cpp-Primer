#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace_all(string &ori, const string &from, const string &to) {
    string::size_type ori_len = ori.size();
    string::size_type from_len = from.size();
    for(string::iterator i = ori.begin(); i < ori.end() - from_len; ++i) {
        if(string(i, i + from_len) == from) {
            ori.erase(i, i + from_len);
            ori.insert(i, to.begin(), to.end());
        }
    }
}

int main() {
    string origin_str = "thoughthough";
    string from_str = "tho";
    string to_str = "thru";
    replace_all(origin_str, from_str, to_str);
    cout << origin_str << endl;
}