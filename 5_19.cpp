#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;
    do {
        cin >> str1 >> str2;
        cout << ((str1.size() > str2.size()) ? str1: str2) << endl;
    }while(cin);
    return 0;
}
