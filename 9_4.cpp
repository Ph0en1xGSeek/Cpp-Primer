#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool find(vector<int>::const_iterator from, vector<int>::const_iterator to, int target) {
    while(from != to) {
        if(*from == target) {
            return true;
        }
        ++from;
    }
    return false;
}

int main() {
    vector<int> v1 = {1,2,3};
    cout << find(v1.cbegin(), v1.cend(), 0) << endl;;
    cout << find(v1.cbegin(), v1.cend(), 1) << endl;;
    return 0;
}