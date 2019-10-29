#include <iostream>
#include <stdio.h>
#include <string>



class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &ptr) : ps(new std::string(*(ptr.ps))), i(ptr.i) { }

    HasPtr& operator=(const HasPtr &ptr) {
        ps = new std::string(*(ptr.ps));
        i = ptr.i;
        return *this;
    }

    std::string get_ps() {
        return *ps;
    }

    int get_i() {
        return i;
    }

private:
    std::string *ps;
    int i;
};


int main() {
    HasPtr hp("123");
    HasPtr hp2 = hp;
    std::cout << hp2.get_ps() << " " << hp2.get_i() << std::endl;
    HasPtr hp3("2222");
    std::cout << hp3.get_ps() << " " << hp3.get_i() << std::endl;
    hp3 = hp2;
    std::cout << hp3.get_ps() << " " << hp3.get_i() << std::endl;
    return 0;
}