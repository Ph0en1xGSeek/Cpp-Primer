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

#include "13_55.h"

int main() {
    StrBlob sb;
    std::string str;
    while(std::getline(std::cin, str)) {
        sb.push_back(str);
    }
    sb.push_back("test move");
    for(StrBlobPtr iter(sb.begin()), pend(sb.end()); iter != pend; iter.incr()) {
        std::cout << iter.deref() << std::endl;
    }

    return 0;
}