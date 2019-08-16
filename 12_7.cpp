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

std::shared_ptr<std::vector<int>> vi_factor(){
    return std::make_shared<std::vector<int>>();
}

void input(std::shared_ptr<std::vector<int>> vi) {
    int tmp;
    while(std::cin >> tmp) {
        vi->push_back(tmp);
    }
}

void output(std::shared_ptr<std::vector<int>> vi) {
    for(auto item: *vi) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}



int main() {
    std::shared_ptr<std::vector<int>> vi = vi_factor();
    input(vi);
    output(vi);
    return 0;
}