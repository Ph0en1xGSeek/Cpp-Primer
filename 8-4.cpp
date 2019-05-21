#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read (const string &filename, vector<string> &vec){
   ifstream ifs(filename);
   string read_str;
   while(getline(ifs, read_str)) {
       vec.push_back(read_str);
   }
}

int main() {
    string filename("./input.txt");
    vector<string> vec;
    read(filename, vec);
    for(string str: vec) {
        cout << str << endl;
    }
    return 0;
}