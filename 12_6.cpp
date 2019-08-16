#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <map>
#include <memory>

std::vector<int>* vi_factor(){
    return new std::vector<int>;
}

void input(std::vector<int> *vi) {
    int tmp;
    while(std::cin >> tmp) {
        vi->push_back(tmp);
    }
}

void output(std::vector<int> *vi) {
    for(auto item: *vi) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}



int main() {
    std::vector<int> *vi = vi_factor();
    input(vi);
    output(vi);
    delete vi;
    return 0;
}