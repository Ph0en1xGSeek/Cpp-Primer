#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num1, num2;
    while(cin >> num1 >> num2) {
        try {
            if(num2 == 0) {
                throw runtime_error("divide 0");
            }
            cout << num1 / num2 << endl;
        }catch(runtime_error err) {
            cout << err.what() << endl;
            cout << "input other numbers? (input y or n)" << endl;
            char ch;
            cin >> ch;
            if(cin.eof() || ch == 'n')
                break;
        }

    }
    return 0;
}
