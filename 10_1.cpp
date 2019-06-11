#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    vector<int> nums;
    int tmp;
    int target = 6;
    while(cin >> tmp) {
        nums.push_back(tmp);
    }
    int cnt = count(nums.cbegin(), nums.cend(), target);
    cout << cnt << endl;
    return 0;
}