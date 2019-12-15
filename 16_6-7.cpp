#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T, unsigned size>
T* begin_def(T (&arr)[size]) {
    return arr;
}

template<typename T, unsigned size>
T* end_def(T (&arr)[size]) {
    return arr + size;
}

template<typename T, unsigned size>
constexpr unsigned getSize(T (&arr)[size]) {
    return size;
}


int main() {
    int iarr[] = {1,2,3};
    string sarr[] = {"22", "5gf", "eeg"};
    cout << *(begin_def(iarr)) << endl;
    cout << *(end_def(sarr) - 1) << endl;
    cout << getSize(iarr) << endl;
    return 0;
}