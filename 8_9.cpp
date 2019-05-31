#include <iostream>
#include <sstream>

using namespace std;

istream &func(istream &is) {
    string str;
    while(is >> str) {
        cout << str << endl;
    }
    is.clear();
    return is;
}


int main() {
    istringstream iss("djsh dddd aaaa gggg");
    func(iss);
    return 0;
}