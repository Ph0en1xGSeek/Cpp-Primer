#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;
void fcn() {
    int i = 5;
    auto f = [&]()->bool{return i > 0 ? !--i: !i;};
    while(!f()) {
        cout << "a ";
    }
    cout << endl;
}

int main() {
    fcn();
}