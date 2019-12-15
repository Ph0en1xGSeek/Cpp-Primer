#include <stdio.h>
#include <iostream>

using namespace std;

template<typename T>
bool compare(const T& a, const T& b) {
    if(a < b) {
        return -1;
    }
    if(b < a) {
        return 1;
    }
    return 0;
}


int main() {
    cout << compare(1, 0) << endl;
    cout << compare(0, 1) << endl;
    cout << compare(3.3, 3.3) << endl;
    return 0;
}