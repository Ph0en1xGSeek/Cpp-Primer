#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream ifs("input.txt");
    vector<string> content;
    string str;
    while(getline(ifs, str)) {
        content.push_back(str);
    }

    for(string &row: content) {
        istringstream iss(row);
        while(iss >> str) {
            cout << str << endl;
        }
    }
    return 0;
}