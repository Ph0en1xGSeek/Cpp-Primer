#include <bits/stdc++.h>

using namespace std;

int sum(initializer_list<int> il) {
    int tot = 0;
    for(int num: il) {
        tot += num;
    }
    return tot;
}

int main()
{
    int result = sum({1,2,3,4,5});
    cout << result << endl;
    return 0;
}
