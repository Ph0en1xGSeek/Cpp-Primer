#include <iostream>

using namespace std;

void print_state(istream &is) {
    cout << is.rdstate() << ' ';
    cout << is.fail() << ' ';
    cout << is.eof() << ' ';
    cout << is.bad() << ' ';
    cout << is.good() << ' ';
    cout << endl;
}

istream &func(istream &is) {
    string str;
    while(is >> str) {
        cout << str << endl;
    }
    is.clear();
    return is;
}


int main() {
    print_state(func(cin));
    return 0;
}