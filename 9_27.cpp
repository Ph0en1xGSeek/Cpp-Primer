#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    forward_list<int> f_list(begin(ia), end(ia));
    auto prev = f_list.before_begin();
    auto curr = f_list.begin();
    while(curr != f_list.end()) {
        if(*curr % 2 == 1) {
            curr = f_list.erase_after(prev);
        }else {
            ++curr;
            ++prev;
        }
    }
    for(auto item: f_list) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}