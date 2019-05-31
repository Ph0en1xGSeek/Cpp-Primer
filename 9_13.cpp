#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>


using namespace std;


int main() {
    list<int> ilist(4, 0);
    vector<int> ivector(4, 1);
    vector<double> dvector(ilist.begin(), ilist.end());
    for(auto item: dvector) {
        cout << item << ' ';
    }
    cout << endl;
    vector<double> dvector2(ivector.begin(), ivector.end());
    for(auto item: dvector2) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}