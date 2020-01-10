#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
    std::vector<std::string> svec{"1", "33", "", "eee"};

    std::function<bool (const std::string&)> fcn = &std::string::empty;
    auto rs1 = std::count_if(svec.begin(), svec.end(), fcn);
    std::cout << "function: " << rs1 << std::endl;

    auto rs2 = std::count_if(svec.begin(), svec.end(), mem_fn(&std::string::empty));
    std::cout << "mem_fn: " << rs2 << std::endl;

    auto rs3 = std::count_if(svec.begin(), svec.end(), std::bind(&std::string::empty, std::placeholders::_1));
    std::cout << "bind: " << rs3 << std::endl;
	return 0;
}