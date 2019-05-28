#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> iv(begin(ia), end(ia));
    list<int> il(begin(ia), end(ia));
    for(auto it = il.begin(); it != il.end(); ) {
        if(*it % 2 == 1) {
            it = il.erase(it);
        }else {
            ++it;
        }
    }
    for(auto it = iv.begin(); it != iv.end(); ) {
        if(*it % 2 == 0) {
            it = iv.erase(it);
        }else {
            ++it;
        }
    }
    for(auto item: il) {
        cout << item << ' ';
    }
    cout << endl;
    for(auto item: iv) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}