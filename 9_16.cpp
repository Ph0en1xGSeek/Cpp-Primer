#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <set>
#include <stdio.h>

using namespace std;

int main() {
    list<int> l1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4,5};
    vector<int> v3 = {1,3,5,7,9};
    cout << (vector<int>(l1.begin(), l1.end()) == v2) << endl;
    cout << (vector<int>(l1.begin(), l1.end()) == v3) << endl;
    return 0;
}