#include <iostream>
#include <stdio.h>
#include <string>



class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &ptr) : ps(new std::string(*(ptr.ps))), i(ptr.i) { 
        std::cout << "copy" << std::endl;
    }

    HasPtr& operator=(const HasPtr &ptr) {
        std::cout << "assignment" << std::endl;
        std::string *new_p = new std::string(*(ptr.ps)); // avoid assigning to itself
        delete ps;
        ps = new_p;
        i = ptr.i;
        return *this;
    }

    ~HasPtr() {
        std::cout << "destructor" << std::endl;
        delete ps;
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

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}


int main() {
    HasPtr hp("123");
    HasPtr hp2 = hp;
    std::cout << hp2.get_ps() << " " << hp2.get_i() << std::endl;
    HasPtr hp3("2222");
    std::cout << hp3.get_ps() << " " << hp3.get_i() << std::endl;
    swap(hp, hp3);
    std::cout << hp.get_ps() << " " << hp.get_i() << std::endl;
    hp3 = hp;
    std::cout << hp3.get_ps() << " " << hp3.get_i() << std::endl;
    return 0;
}