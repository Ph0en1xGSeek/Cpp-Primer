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
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    cout << add(1, 3) << endl;
}
 
 