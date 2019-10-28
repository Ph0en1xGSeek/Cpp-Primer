#include <iostream>
#include <stdio.h>
#include <string>



class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &ptr) : ps(new std::string(*(ptr.ps))), i(ptr.i) { }

private:
    std::string *ps;
    int i;
};


int main() {
    HasPtr hp("123");
    HasPtr hp2 = hp;
    return 0;
}