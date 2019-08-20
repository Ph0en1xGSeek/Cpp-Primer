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
    char *concat_str = new char[(strlen("hello ") + strlen("world") + 1)]();
    strcat(concat_str, "hello ");
    strcat(concat_str, "world");
    std::cout << concat_str << std::endl;
    delete [] concat_str;

    std::string str1{"hello "};
    std::string str2{"world"};
    std::cout << str1 + str2 << std::endl;

    return 0;
}