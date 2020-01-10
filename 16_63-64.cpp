#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

template<typename T>
size_t count(const vector<T> &vec, T value) {
    size_t cnt = 0;
    for(auto elem: vec) {
        if(elem == value) {
            ++cnt;
        }
    }
    return cnt;
}

template<>
size_t count(const vector<const char*> &vec, const char* value) {
    cout << "specialized" << endl;
    size_t cnt = 0;
    for(auto elem: vec) {
        if(elem == value) {
            ++cnt;
        }
    }
    return cnt;
}


int main() {
    
    vector<int> ivec({1,2,34,5,1,2,6,672,12,4,6});
    cout << count(ivec, 1) << endl;
    vector<string> strvec({"dfsf", "aaa", "fdf", "aaa", "rr"});
    cout << count<string>(strvec, "aaa") << endl;

    vector<const char*> vcc({"dfsf", "aaa", "fdf", "aaa", "rr"});
    cout << count(vcc, "aaa") << endl;
    return 0;
}