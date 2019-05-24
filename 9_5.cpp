#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

vector<int>::const_iterator find(vector<int>::const_iterator from, vector<int>::const_iterator to, int target) {
    while(from != to) {
        if(*from == target) {
            return from;
        }
        ++from;
    }
    return to;
}

int main() {
    vector<int> v1 = {1,2,3};
    vector<int>::const_iterator iter = find(v1.cbegin(), v1.cend(), 1);
    if(iter == v1.end()) {
        cout << "Not Found" << endl;
    }else {
        cout << *iter << endl;
    }
    return 0;
}