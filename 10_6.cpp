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


int main() {
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    fill_n(vec.begin(), 10, 0);
    for(auto item: vec) {
        cout << item << ' ';
    }
    cout << endl;
}
 