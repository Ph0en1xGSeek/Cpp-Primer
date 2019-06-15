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
    int b = 34;
    auto add = [b](int a) -> int {
        return a + b;
    };
    cout << add(1) << endl;
}
 
 