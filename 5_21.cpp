#include <bits/stdc++.h>

using namespace std;

int main()
{
    string cur, pre = "";
    while(cin >> cur) {
        if(!isupper(cur[0])) {
            continue;
        }
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
