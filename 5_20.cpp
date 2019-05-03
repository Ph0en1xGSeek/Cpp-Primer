#include <bits/stdc++.h>

using namespace std;

int main()
{
    string cur, pre = "";
    while(cin >> cur) {
        if(cur == pre) {
            break;
        }
        pre = cur;
    }
    if(!cin.eof()) {
        cout << cur << endl;
    }else {
        cout << "no word was repeated" << endl;
    }
    return 0;
}
