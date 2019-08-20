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
#include <string.h>


int main() {
    int size = 0;
    std::cin >> size;
    char *str = new char[size];
    std::cin.ignore();
    std::cin.get(str, size+1);
    std::cout << str << std::endl;
    delete [] str;

    return 0;
}