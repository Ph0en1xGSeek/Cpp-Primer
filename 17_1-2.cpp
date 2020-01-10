#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;



int main() {
    
    tuple<int, int, int> inttuple({10, 20, 30});
    auto int3 = make_tuple(10, 20, 30);
    tuple<string, vector<string>, pair<string, int>> tuple3;
    return 0;
}