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
    vector<int> nums {1,2,3,4,5};
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    cout << sum << endl;
    return 0;
}
 