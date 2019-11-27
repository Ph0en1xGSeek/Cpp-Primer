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

#include "14_28_StrBlobPtr.h"

int main() {
    StrBlob sb;
    std::string str;
    while(std::getline(std::cin, str)) {
        sb.push_back(str);
    }
    for(StrBlobPtr iter(sb.begin()), pend(sb.end()); iter != pend; iter++) {
        std::cout << iter.deref() << std::endl;
    }
    std::cout << "subscribe " << sb[0] << std::endl;

    return 0;
}