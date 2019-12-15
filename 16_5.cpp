#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void print(T const& arr) {
    for(auto const& elem: arr) {
        cout << elem << endl;
    }
}


int main() {
    int iarr[] = {1,2,3};
    string sarr[] = {"22", "5gf", "eeg"};
    print(iarr);
    print(sarr);
    return 0;
}