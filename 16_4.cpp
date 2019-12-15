#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T, typename I>
auto find(I first, I last, T value) {
    cout << "Using customized find" << endl;
    for(; first != last; ++first) {
        if(*first == value) {
            return first;
        }
    }
    return last;
}


int main() {
    vector<int> vi = {1,4,6,23,76,2,1,6};
    list<string> sl = {"222", "34", "3567"};
    auto vi_iter = find(vi.begin(), vi.end(), 4);
    if(vi_iter != vi.end()) {
        cout << "Found in vi" << endl;
    }else {
        cout << "Not found in vi" << endl;
    }
    
    auto sl_iter = find(sl.begin(), sl.end(), "2333");
    if(sl_iter != sl.end()) {
        cout << "Found in sl" << endl;
    }else {
        cout << "Not found in sl" << endl;
    }
    return 0;
}