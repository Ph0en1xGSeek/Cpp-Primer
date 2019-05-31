#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    string str = "ab2c3d7R4E6";
    string number = "1234567890";
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(string::size_type pos = 0; (pos = str.find_first_of(number, pos)) != string::npos; ++pos) {
        cout << "number index: " << pos << endl;
    }
    for(string::size_type pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos) {
        cout << "alphabet index: " << pos << endl;
    }
    for(string::size_type pos = 0; (pos = str.find_first_not_of(number, pos)) != string::npos; ++pos) {
        cout << "not number index: " << pos << endl;
    }
    for(string::size_type pos = 0; (pos = str.find_first_not_of(alphabet, pos)) != string::npos; ++pos) {
        cout << "not alphabet index: " << pos << endl;
    }
}