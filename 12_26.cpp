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
    int n = 20;
    std::allocator<std::string> alloc;
    std::string * const p = alloc.allocate(n);
    std::string str;
    std::string *q = p;
    while(std::cin >> str && q != p + n) {
        alloc.construct(q++, str);
    }
    const std::size_t sz = q - p;
    std::cout << sz << std::endl;
    while(q != p) {
        std::cout << *--q << std::endl;
    }
    alloc.deallocate(p, n);

    return 0;
}