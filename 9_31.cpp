#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

void manage_forward_list(forward_list<int> &fil) {
    
    auto pre = fil.before_begin();
    for(auto it = fil.begin(); it != fil.end(); ) {
        if(*it % 2 == 1) {
            it = fil.insert_after(pre, *it);
            advance(it, 2);
            advance(pre, 2);
        }else {
            it = fil.erase_after(pre);
        }
    }
}

void manage_list(list<int> &il) {
    for(auto it = il.begin(); it != il.end(); ) {
        if(*it % 2 == 1) {
            it = il.insert(it, *it);
            ++it;
            ++it;
        }else {
            it = il.erase(it);
        }
    }
}

int main() {
    forward_list<int> fil = {0,1,2,3,4,5,6,7,8};
    list<int> il = {0,1,2,3,4,5,6,7,8};

    manage_forward_list(fil);
    manage_list(il);

    for(auto item: fil) {
        cout << item << ' ';
    }
    cout << endl;

    for(auto item: il) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}