#include <iostream>
#include <vector>
#include <string>

using namespace std;


string &add_prefix_suffix(string name, const string &prefix, const string &suffix) {
    name.insert(name.begin(), prefix.begin(), prefix.end());
    return name.append(suffix);
}

int main() {
    string name = "Pan";
    string pre = "Mr.";
    string suf = " Jr.";
    auto ret = add_prefix_suffix(name, pre, suf);
    cout << ret << endl;
}