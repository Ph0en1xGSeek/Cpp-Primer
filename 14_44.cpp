#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>
#include <map>
#include <functional>

using namespace std;

int add(int a, int b) {
    return a + b;
}

auto mod = [] (int a, int b) {return a % b;};

struct Divide {
    int operator()(int a, int b){
        return a / b;
    }
};

auto binops = map<string, function<int(int, int)>> {
    {"+", add},
    {"%", mod},
    {"/", Divide()}
};

int main() {
    int a, b;
    string op;
    while(cin >> a >> op >> b) {
        cout << binops[op](a, b) << endl;
    }  
}
 
 