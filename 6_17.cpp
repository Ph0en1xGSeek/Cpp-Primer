#include <bits/stdc++.h>

using namespace std;

bool hasUpper(const string &str) {
    for(auto ch: str) {
        if(isupper(ch)){
            return true;
        }
    }
    return false;
}

void toLower(string &str) {
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= 'A' - 'a';
        }
    }
}

int main()
{
    string str = "Hello World!";
    cout << hasUpper(str) << endl;
    cout << str << endl;
    toLower(str);
    cout << str << endl;

    return 0;
}
