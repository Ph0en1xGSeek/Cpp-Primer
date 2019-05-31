#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<char> ch_arr = {'a', 'b', 'c'};
    string str(ch_arr.begin(), ch_arr.end());
    cout << str << endl;
    return 0;
}