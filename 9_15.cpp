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
#define NUM_CHARACTER 26

using namespace std;

int main() {
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {1,3,5,7,9};
    cout << (v1 > v2) << endl;
    cout << (v2 > v3) << endl;
    return 0;
}