#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

void insert_after_string(forward_list<string> &f_list, const string &str1, const string &str2) {
    auto prev = f_list.before_begin();
    for(auto it = f_list.begin(); it != f_list.end(); prev = it++) {
        if(*it == str1) {
            f_list.insert_after(it, str2);
            return;
        }
    }
    f_list.insert_after(prev, str2);
}

int main() {
    forward_list<string> f_list = {"111", "222", "333"};
    insert_after_string(f_list, "111", "666");
    insert_after_string(f_list, "123", "321");
    for(auto item: f_list) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}