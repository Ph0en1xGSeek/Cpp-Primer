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

void println(vector<int> &vec){
    for(auto item: vec) {
        cout << item << ' ';
    }
    cout << endl;
}

void elimDups(vector<int> &vec) {
    println(vec);
    sort(vec.begin(), vec.end());
    println(vec);
    unique(vec.begin(), vec.end());
    println(vec);
}


int main() {
    vector<int> vec = {0,3,6,2,67,2,3,4,5,2,4};
    elimDups(vec);
}
 