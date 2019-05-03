#include <bits/stdc++.h>

using namespace std;

int main()
{
    string pre = "";
    string cur;
    int cur_mx = 0, mx = 0;
    string mx_str;
    while(cin >> cur) {
        if(cur == pre) {
            if(cur_mx == 0){
                cur_mx = 2;
            }else {
                ++cur_mx;
            }
            if(cur_mx > mx) {
                mx = cur_mx;
                mx_str = cur;
            }
        }else {
            cur_mx = 0;
        }
        pre = cur;
    }
    cout << mx_str << " " << mx << endl;
    return 0;
}
