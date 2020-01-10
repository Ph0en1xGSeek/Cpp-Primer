#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory>
#include <bitset>

using namespace std;



int main() {
    
    bitset<30> bs;
    vector<int> ivec = {1,2,3,5,8,13,21};
    for(int elem : ivec) {
        bs.set(elem);
    }
    cout << bs << endl;
    return 0;
}