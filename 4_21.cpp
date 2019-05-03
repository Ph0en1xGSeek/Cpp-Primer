#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,4,5,6};
    for(auto &i: ivec) {
        i = ((i&1) == 1 ? i*2: i);
    }
    for(auto i: ivec) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
