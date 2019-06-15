#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

void println(vector<string> &vec){
    for(auto item: vec) {
        cout << item << ' ';
    }
    cout << endl;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &vec) {
    println(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    println(vec);
    unique(vec.begin(), vec.end());
    println(vec);
}


int main() {
    vector<string> vec = {"g", "asd", "dfdfs", "ffff", "dddd", "a", "aaaaa"};
    elimDups(vec);
}
