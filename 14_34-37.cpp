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

class Test {
public:
    int operator()(bool con, int a, int b) {
        return con? a: b;
    }
};

class PrintString {
public:
    PrintString(std::istream &is_ = std::cin): is(is_){}
    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is? str: std::string();
    }

private:
    std::istream &is;
};

class IsEqual {
    int value;
public:
    IsEqual(int v): value(v) {}
    bool operator()(int elem) {
        return elem == value;
    }
};

int main() {
    Test test;
    std::cout << test(true, 1, 0) << std::endl; 

    PrintString ps(std::cin);
    std::vector<std::string> arr;
    for(int i = 0; i < 5; ++i) {
        arr.push_back(ps());
    }

    IsEqual ie(3);
    std::vector<int> il = {1,2,3,4,5,6,7,3};
    std::replace_if(il.begin(), il.end(), ie, 5);
    for(int i = 0; i < il.size(); ++i) {
        std::cout << il[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}